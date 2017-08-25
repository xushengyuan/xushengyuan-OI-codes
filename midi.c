//=============================================================================
//���ߣ�0xAA55
//��̳��http://www.0xaa55.com/
//��Ȩ����(C) 2013-2014 ����լ�Ľ��
//�뱣��ԭ������Ϣ��������Ϊ��Ȩ��
//-----------------------------------------------------------------------------
#include<stdio.h>
#include<malloc.h>

//ͳһ���ͳ���
typedef signed int      MIDIInt,*MIDIIntP;
typedef signed char     MIDIInt8,*MIDIInt8P;
typedef signed short    MIDIInt16,*MIDIInt16P;
typedef signed long     MIDIInt32,*MIDIInt32P;
typedef unsigned int    MIDIUInt,*MIDIUIntP;
typedef unsigned char   MIDIUInt8,*MIDIUInt8P;
typedef unsigned short  MIDIUInt16,*MIDIUInt16P;
typedef unsigned long   MIDIUInt32,*MIDIUInt32P;

typedef MIDIUInt8       BYTE;
typedef MIDIUInt16      WORD;
typedef MIDIUInt32      DWORD;

//MIDI�ļ�ͷ�Ľṹ��
typedef struct
{
    DWORD   dwFlag;             //MThd��ʶ
    DWORD   dwRestLen;          //ʣ�ಿ�ֳ���
    WORD    wType;              //����
    WORD    wNbTracks;          //������
    WORD    wTicksPerCrotchet;  //ÿ�ķ�������Tick��
}MIDIHeader,*MIDIHeaderP;

//MIDI�ļ��г��ֹ��ı�ʶ
#define MIDI_MThd   0x6468544D
#define MIDI_MTrk   0x6B72544D

//MIDI�ļ�ͷ�ġ����͡�
#define MIDIT_SingleTrack   0   /*������*/
#define MIDIT_MultiSync     1   /*ͬ��������*/
#define MIDIT_MultiAsync    2   /*�첽������*/

//���ֳ��ȵ�Big-Endian��Little-Endian��ת��
#define BSwapW(x)   ((((x) & 0xFF)<<8)|(((x) & 0xFF00)>>8))
#define BSwap24(x)  ((((x) & 0xFF)<<16)|((x) & 0xFF00)|(((x) & 0xFF0000)>>16))
#define BSwapD(x)   ((((x) & 0xFF)<<24)|(((x) & 0xFF00)<<8)|(((x) & 0xFF0000)>>8)|(((x) & 0xFF000000)>>24))

//�������ֽ�ת�����ַ����ĺ���
char*NoteToString(BYTE bNote);

//��ȡ�ַ���Ȼ���ӡ
size_t ReadStringAndPrint(FILE*,size_t);

//=============================================================================
//ReadDynamicBytes:
//��ȡ��̬�ֽڣ�����ȡ4�ֽڡ����ض�ȡ���ֽ���
//-----------------------------------------------------------------------------
size_t ReadDynamicBytes(FILE*fp,DWORD*pOut)
{
    size_t bBytesRead;//�Ѷ�ȡ���ֽ���
    *pOut=0;
    for(bBytesRead=1;bBytesRead<=4;bBytesRead++)//����ȡ4�ֽ�
    {
        int iValue=fgetc(fp);
        if(iValue==EOF)
            return 0;
        *pOut=(*pOut<<7)|(iValue & 0x7F);//�¶�����ǵ�λ
        if(!(iValue & 0x80))//���û�к����ֽ�
            break;//��ֹͣ��ȡ��
    }
    return bBytesRead;//���ض�ȡ���ֽ���
}

//=============================================================================
//ParseMIDI:
//����MIDI�ļ���ʧ�ܷ����㣬�ɹ����ط���
//-----------------------------------------------------------------------------
int ParseMIDI(char*pszFileName)
{
#   define READERR {fprintf(stderr,"��ȡ�ļ�%s��������\n",pszFileName);goto BadReturn;}
#   define FMTERR {fprintf(stderr,"%s����һ��������MIDI�ļ�\n",pszFileName);goto BadReturn;}
#   define READ(x) if(fread(&(x),1,sizeof(x),fp)!=sizeof(x))READERR

    FILE*fp;
    MIDIHeader midiHeader;
    size_t i;

    //���ļ�
    fp=fopen(pszFileName,"rb");
    if(!fp)
        READERR;

    //MIDI�ļ�ͷ����һ��MIDIHeader�ṹ�塣
    //����Ҫע�����е���ֵ����Big-Endian�洢��
    //��Ҫ����ת��

    //��ȡMIDI�ļ�ͷ
    READ(midiHeader);
    
    //����ļ���ʽ
    if(midiHeader.dwFlag!=MIDI_MThd)//��ʶ������"MThd"
        FMTERR;

    //ת��ΪLittle-Endian
    midiHeader.dwRestLen=           BSwapD(midiHeader.dwRestLen);
    midiHeader.wType=               BSwapW(midiHeader.wType);
    midiHeader.wNbTracks=           BSwapW(midiHeader.wNbTracks);
    midiHeader.wTicksPerCrotchet=   BSwapW(midiHeader.wTicksPerCrotchet);

    //�����ļ�ͷ
    switch(midiHeader.wType)
    {
    case MIDIT_SingleTrack:
        fputs("����:������\n",stdout);
        break;
    case MIDIT_MultiSync:
        fputs("����:ͬ��������\n",stdout);
        break;
    case MIDIT_MultiAsync:
        fputs("����:�첽������\n",stdout);
        break;
    default:
        fprintf(stdout,"����:δ֪(0x%04X)\n",midiHeader.wType);
        break;
    }

    //��ӡ����������Ϣ
    fprintf(stdout,
        "������:%u\n"
        "ÿ�ķ�����ʱ����:%u\n",
        midiHeader.wNbTracks,
        midiHeader.wTicksPerCrotchet);

    //��ȷ��ת��MIDI�����λ�ã�����midiHeader.dwRestLen�����á���
    fseek(fp,8+midiHeader.dwRestLen,SEEK_SET);

    //׼����ȡ��������
    for(i=0;i<midiHeader.wNbTracks;i++)
    {
        DWORD dwTrackFlag;
        DWORD dwTrackLen;

        //ÿ������Ŀ�ͷ����һ��dwTrackFlag��һ��dwTrackLen
        //dwTrackFlag��ֵ������MIDI_MTrk
        //dwTrackLen�������һ�������λ��

        size_t TrackStartPos;

        fputs("��ȡ����\n",stdout);

        READ(dwTrackFlag);  if(dwTrackFlag!=MIDI_MTrk)FMTERR;//����ļ���ʽ
        READ(dwTrackLen);   TrackStartPos=ftell(fp);//��¼��ǰλ��

        //ת��Big-Endian
        dwTrackLen=BSwapD(dwTrackLen);

        //��ʾÿ��������ֽ���
        fprintf(stdout,"�����С:%u �ֽ�\n",dwTrackLen);

        //�������Ҫ�������¼�����
        for(;;)//ѭ����ȡ�¼�
        {
            DWORD dwDelay;
            BYTE bEvent;

            //ÿ���¼��Ĺ��ɶ��ǣ�
            //��ʱ���¼��ţ�����
            //���е���ʱ�Ƕ�̬�ֽڣ�������С���¼��Ŷ���

            //��һ���¼���
            BYTE bLastEvent;

            //��ȡ��ʱ
            if(!ReadDynamicBytes(fp,&dwDelay))
                READERR;

            //��ȡ�¼���
            READ(bEvent);

            //ÿ��ȡһ���¼�����ӡ����¼���ʱ��
            fprintf(stdout,"ʱ��:%u,",dwDelay);

            //�����¼�
ProcEvent:  if(bEvent <= 0x7F)
            {//0��0x7F:����һ���¼����¼�����ͬ������ȡ������ֽھ�����һ���¼��ŵĲ����ĵ�һ���ֽ�
                fseek(fp,-1,SEEK_CUR);//����һ���ֽ�
                bEvent=bLastEvent;
                goto ProcEvent;
            }
            else if(bEvent <= 0x8F)
            {//0x80��0x8F:�ɿ�����
                BYTE bNote,bVel;

                READ(bNote);//����
                READ(bVel); //����

                fprintf(stdout,"(ͨ��%u)�ɿ�����:%s, ����:%u\n",
                    bEvent & 0xF,//��4λ��ʾͨ����
                    NoteToString(bNote),//����
                    bVel);//����
            }
            else if(bEvent <= 0x9F)
            {//0x90��0x9F:��������
                BYTE bNote,bVel;

                READ(bNote);//����
                READ(bVel); //����

                fprintf(stdout,"(ͨ��%u)��������:%s, ����:%u\n",
                    bEvent & 0xF,//��4λ��ʾͨ����
                    NoteToString(bNote),//����
                    bVel);//����
            }
            else if(bEvent <= 0xAF)
            {//0xA0��0xAF:��������
                BYTE bNote,bVel;

                READ(bNote);//����
                READ(bVel); //����

                fprintf(stdout,"(ͨ��%u)��������:%s, ����:%u\n",
                    bEvent & 0xF,//��4λ��ʾͨ����
                    NoteToString(bNote),//����
                    bVel);//����
            }
            else if(bEvent <= 0xBF)
            {//0xB0��0xBF:������
                BYTE bReg,bVal;

                READ(bReg);//�Ĵ�����
                READ(bVal);//�Ĵ���ֵ

                fprintf(stdout,"(ͨ��%u)������:%u,ֵ=%u\n",
                    bEvent & 0xF,//��4λ��ʾͨ����
                    bReg,//�Ĵ���
                    bVal);//ֵ
            }
            else if(bEvent <= 0xCF)
            {//0xC0��0xCF:�ı�����
                BYTE bInstrument;

                READ(bInstrument);//������
                
                fprintf(stdout,"(ͨ��%u)�ı�����:%u\n",
                    bEvent & 0xF,//��4λ��ʾͨ����
                    bInstrument);//������
            }
            else if(bEvent <= 0xDF)
            {//0xD0��0xDF:����ͨ��
                BYTE bChannel;

                READ(bChannel);//ͨ����
                
                fprintf(stdout,"(ͨ��%u)����ͨ��:%u\n",
                    bEvent & 0xF,//��4λ��ʾͨ����
                    bChannel);//ͨ����
            }
            else if(bEvent <= 0xEF)
            {//0xE0��0xEF:����
                WORD wPitch;//����������Little-Endian��WORD

                READ(wPitch);
                
                fprintf(stdout,"(ͨ��%u)����:%u\n",
                    bEvent & 0xF,//��4λ��ʾͨ����
                    wPitch);//����
            }
            else if(bEvent == 0xF0)
            {//0xF0:ϵͳ��
                BYTE bSysCode=0;

                fputs("ϵͳ��:",stdout);
                for(;;)
                {
                    READ(bSysCode);
                    if(bSysCode!=0xF7)
                        fprintf(stdout,"0x%02X,",bSysCode);
                    else
                    {
                        fprintf(stdout,"0x%02X\n",bSysCode);
                        break;//��ȡ��0xF7����
                    }
                }
            }
            else if(bEvent == 0xFF)
            {//Ԫ�¼�
                BYTE bType,bBytes;
                size_t CurrentPos;
                
                READ(bType);//Ԫ��������
                READ(bBytes);//Ԫ�����ֽ���

                CurrentPos=ftell(fp);//��¼Ԫ���ݶ�ȡ��λ��

                fputs("Ԫ���� - ",stdout);

                switch(bType)
                {
                case 0x00://���ù������
                    {
                        WORD wTrackSeq;
                        READ(wTrackSeq);
                        wTrackSeq=BSwapW(wTrackSeq);
                        fprintf(stdout,"���ù������:0x%04X\n",wTrackSeq);
                    }
                    break;
                case 0x01://������ע
                    fputs("��ע:",stdout);
                    ReadStringAndPrint(fp,bBytes);
                    fputc('\n',stdout);
                    break;
                case 0x02://��Ȩ
                    fputs("��Ȩ:",stdout);
                    ReadStringAndPrint(fp,bBytes);
                    fputc('\n',stdout);
                    break;
                case 0x03://��������
                    fputs("����:",stdout);
                    ReadStringAndPrint(fp,bBytes);
                    fputc('\n',stdout);
                    break;
                case 0x04://��������
                    fputs("������:",stdout);
                    ReadStringAndPrint(fp,bBytes);
                    fputc('\n',stdout);
                    break;
                case 0x05://���
                    fputs("���:",stdout);
                    ReadStringAndPrint(fp,bBytes);
                    fputc('\n',stdout);
                    break;
                case 0x06://���
                    fputs("���:",stdout);
                    ReadStringAndPrint(fp,bBytes);
                    fputc('\n',stdout);
                    break;
                case 0x07://��ʼ��
                    fputs("��ʼ��:",stdout);
                    ReadStringAndPrint(fp,bBytes);
                    fputc('\n',stdout);
                    break;
                case 0x21://���쿪ʼ��ʶ
                    fputs("���쿪ʼ��ʶ.\n",stdout);
                    break;
                case 0x2F://���������ʶ
                    fputs("���������ʶ.\n",stdout);
                    goto EndOfTrack;
                case 0x51://�ٶ�
                    {
                        BYTE bVelocity1,bVelocity2,bVelocity3;

                        //�ٶ���24λ������һ���ķ�������΢������
                        READ(bVelocity1);
                        READ(bVelocity2);
                        READ(bVelocity3);

                        //������Big-Endian
                        fprintf(stdout,"�ٶ�: ÿ�ķ�����%u΢��.\n",
                            bVelocity3|(bVelocity2<<8)|(bVelocity1<<16));
                    }
                    break;
                case 0x58://����
                    {
                        BYTE bBeatNumerator,bBeatDenominator,bMetronomeTimer,bNb32ndNotesInCrotchet;

                        READ(bBeatNumerator);//����
                        READ(bBeatDenominator);//��ĸ
                        READ(bMetronomeTimer);//������ʱ��
                        READ(bNb32ndNotesInCrotchet);//ÿ�ķ������ж�����ʮ��������

                        fprintf(stdout,"����:%u/%u. ������ʱ��:%u. ÿ�ķ�������%u����ʮ��������.\n",
                            bBeatNumerator,bBeatDenominator,bMetronomeTimer,bNb32ndNotesInCrotchet);
                    }
                    break;
                case 0x59://����
                    {
                        MIDIInt8 bTunePitch;
                        BYTE bTuneType;

                        READ(bTunePitch);//������
                        READ(bTuneType);//�����С��

                        fprintf(stdout,"������:%d, ",bTunePitch);
                        switch(bTuneType)
                        {
                        case 0://���
                            fputs("���\n",stdout);
                            break;
                        case 1://С��
                            fputs("С��\n",stdout);
                            break;
                        default://��֪��
                            fprintf(stdout,"δ֪��(0x%02X).\n",bTuneType);
                            break;
                        }
                    }
                    break;
                case 0x7F://�����ض���Ϣ
                    fputs("�����ض���Ϣ:",stdout);
                    ReadStringAndPrint(fp,bBytes);
                    fputc('\n',stdout);
                    break;
                default:
                    fprintf(stdout,"δ֪Ԫ��������(0x%02X)\n",bType);
                    break;
                }

                fseek(fp,CurrentPos+bBytes,SEEK_SET);//��ȡ��ɺ���ȷ������һ���¼���λ�á�
            }
            else//�����¼���δ֪�¼�
            {
                fprintf(stdout,"δ֪�¼�:0x%08X. ֹͣ��ǰ����ķ�����\n",bEvent);
                break;
            }

            //��¼��һ���¼���
            bLastEvent=bEvent;
        }//��ȥ������ȡ�¼���

EndOfTrack:
        fseek(fp,TrackStartPos+dwTrackLen,SEEK_SET);//ת����һ������
    }

    fputs("MIDI�ļ���ȡ������\n",stdout);

    fclose(fp);
    return 1;
BadReturn:
    fclose(fp);
    return 0;

#   undef READ
#   undef READERR
}

//=============================================================================
//NoteToString:
//����������ת��Ϊ�ַ���
//��ʵÿ�η��صĶ���ͬһ��������ֻ��ÿ�ζ���д�˻�������ֵ��
//-----------------------------------------------------------------------------
char*NoteToString(BYTE bNote)
{
    static char szBuf[5];//����5�ַ�
    switch(bNote % 12)
    {
    case 0:
        sprintf(szBuf,"C%d",(int)(bNote / 12)-2);
        break;
    case 1:
        sprintf(szBuf,"C%d#",(int)(bNote / 12)-2);
        break;
    case 2:
        sprintf(szBuf,"D%d",(int)(bNote / 12)-2);
        break;
    case 3:
        sprintf(szBuf,"D%d#",(int)(bNote / 12)-2);
        break;
    case 4:
        sprintf(szBuf,"E%d",(int)(bNote / 12)-2);
        break;
    case 5:
        sprintf(szBuf,"F%d",(int)(bNote / 12)-2);
        break;
    case 6:
        sprintf(szBuf,"F%d#",(int)(bNote / 12)-2);
        break;
    case 7:
        sprintf(szBuf,"G%d",(int)(bNote / 12)-2);
        break;
    case 8:
        sprintf(szBuf,"G%d#",(int)(bNote / 12)-2);
        break;
    case 9:
        sprintf(szBuf,"A%d",(int)(bNote / 12)-2);
        break;
    case 10:
        sprintf(szBuf,"A%d#",(int)(bNote / 12)-2);
        break;
    case 11:
        sprintf(szBuf,"B%d",(int)(bNote / 12)-2);
        break;
    }
    return szBuf;
}

//=============================================================================
//ReadStringAndPrint
//��ȡ�ַ���Ȼ���ӡ�����ض�ȡ���ֽ���
//-----------------------------------------------------------------------------
size_t ReadStringAndPrint(FILE*fp,size_t szLength)
{
    char*pBuf;
    pBuf=(char*)malloc(szLength+1);
    if(pBuf)//�����ڴ�һ�ζ�ȡ
    {
        size_t Ret=fread(pBuf,1,szLength,fp);
        pBuf[szLength]=0;//��β��\0
        fputs(pBuf,stdout);
        free(pBuf);
        return Ret;
    }
    else
    {
        fputs("�޷����ַ��������ڴ档\n",stderr);
        return 0;
    }
}

//=============================================================================
//main:
//���
//-----------------------------------------------------------------------------
int main(int argc,char**argv)
{
    if(argc<2)
    {
        fprintf(stderr,
            "Usage:\n"
            "%s midifile.mid\n",argv[0]?argv[0]:"MIDIFile");
        return 1;
    }

    ParseMIDI(argv[1]);
    return 0;
}