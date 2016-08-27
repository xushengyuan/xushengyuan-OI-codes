#pragma once

#include "waifu2x.h"


class stImage
{
private:
	cv::Mat mOrgFloatImage;
	int mOrgChannel;
	cv::Size_<int> mOrgSize;

	bool mIsRequestDenoise;

	cv::Mat mTmpImageRGB; // RGB(���邢��Y)
	cv::Mat mTmpImageA; // ���`�����l��

	cv::Mat mEndImage; // ���������摜

	int pad_w1;
	int pad_h1;
	int pad_w2;
	int pad_h2;

public:
	struct stOutputExtentionElement
	{
		std::wstring ext;
		std::vector<int> depthList;
		boost::optional<int> imageQualityStart;
		boost::optional<int> imageQualityEnd;
		boost::optional<int> imageQualityDefault;
		boost::optional<int> imageQualitySettingVolume;
	};

	const static std::vector<stOutputExtentionElement> OutputExtentionList;

private:
	static Waifu2x::eWaifu2xError LoadMatBySTBI(cv::Mat &im, const std::vector<char> &img_data);

	static cv::Mat ConvertToFloat(const cv::Mat &im);

	static Waifu2x::eWaifu2xError AlphaMakeBorder(std::vector<cv::Mat> &planes, const cv::Mat &alpha, const int offset);

	static cv::Mat DeconvertFromFloat(const cv::Mat &im, const int depth);
	static void AlphaCleanImage(cv::Mat &im);

	static Waifu2x::eWaifu2xError WriteMat(const cv::Mat &im, const boost::filesystem::path &output_file, const boost::optional<int> &output_quality);

	void ConvertToNetFormat(const int input_plane, const int alpha_offset);

	Waifu2x::eWaifu2xError CreateBrightnessImage(const cv::Mat &float_image, cv::Mat &im);
	void PaddingImage(const cv::Mat &input, const int net_offset, const int outer_padding,
		const int crop_w, const int crop_h, cv::Mat &output);
	Waifu2x::eWaifu2xError CreateZoomColorImage(const cv::Mat &float_image, const cv::Size_<int> &zoom_size, std::vector<cv::Mat> &cubic_planes);

	// �g��A�p�f�B���O���ꂽ�摜���擾
	// ���̊֐����Ăяo������AmTmpImageRGB�͋�ɂȂ�̂Œ���
	void GetScalePaddingedImage(cv::Mat &in, cv::Mat &out, cv::Size_<int> &size, const int net_offset, const int outer_padding,
		const int crop_w, const int crop_h, const int scale);

	// �ϊ����ꂽ�摜��ݒ�
	// size: GetScalePaddingedImage()�Ŏ擾����size
	void SetReconstructedImage(cv::Mat &dst, cv::Mat &src, const cv::Size_<int> &size, const int inner_scale);

	void DeconvertFromNetFormat(const int input_plane);
	void ShrinkImage(const double scale);

	static int DepthBitToCVDepth(const int depth_bit);
	static double GetValumeMaxFromCVDepth(const int cv_depth);
	static double GetEPS(const int cv_depth);

public:
	stImage();
	~stImage();

	void Clear();

	static Waifu2x::eWaifu2xError LoadMat(cv::Mat &im, const boost::filesystem::path &input_file);

	Waifu2x::eWaifu2xError Load(const boost::filesystem::path &input_file);

	// source: (4�`�����l���̏ꍇ��)RGBA�ȉ�f�z��
	// dest: (4�`�����l���̏ꍇ��)��������RGBA�ȉ�f�z��
	// width: width�̏c��
	// height: height�̉���
	// channel: source�̃`�����l����
	// stride: source�̃X�g���C�h(�o�C�g�P��)
	// source��Postprocess()���I���܂ő��݂��Ă���K�v������
	Waifu2x::eWaifu2xError Load(const void* source, const int width, const int height, const int channel, const int stride);

	double GetScaleFromWidth(const int width) const;
	double GetScaleFromHeight(const int width) const;

	bool RequestDenoise() const;

	// �O����
	// RGB���f���̏ꍇ�͂��ꂪ�I��������ɂ�mOrgFloatImage����ɂȂ��Ă���̂Œ���
	void Preprocess(const int input_plane, const int net_offset);

	bool HasAlpha() const;

	// �g��A�p�f�B���O���ꂽ�摜���擾
	// ���̊֐����Ăяo������AmTmpImageRGB�͋�ɂȂ�̂Œ���
	void GetScalePaddingedRGB(cv::Mat &im, cv::Size_<int> &size, const int net_offset, const int outer_padding,
		const int crop_w, const int crop_h, const int scale);

	// �ϊ����ꂽ�摜��ݒ�
	// ���̊֐����Ăяo������Aim�͋�ɂȂ�̂Œ���
	// size: GetScalePaddingedImage()�Ŏ擾����size
	void SetReconstructedRGB(cv::Mat &im, const cv::Size_<int> &size, const int inner_scale);

	// �g��A�p�f�B���O���ꂽ�摜���擾
	// ���̊֐����Ăяo������AmTmpImageA�͋�ɂȂ�̂Œ���
	void GetScalePaddingedA(cv::Mat &im, cv::Size_<int> &size, const int net_offset, const int outer_padding,
		const int crop_w, const int crop_h, const int scale);

	// �g�傳�ꂽ�摜��ݒ�
	// ���̊֐����Ăяo������Aim�͋�ɂȂ�̂Œ���
	// size: GetScalePaddingedImage()�Ŏ擾����size
	void SetReconstructedA(cv::Mat &im, const cv::Size_<int> &size, const int inner_scale);

	void Postprocess(const int input_plane, const double scale, const int depth);

	cv::Mat GetEndImage() const;

	Waifu2x::eWaifu2xError Save(const boost::filesystem::path &output_file, const boost::optional<int> &output_quality);
};
