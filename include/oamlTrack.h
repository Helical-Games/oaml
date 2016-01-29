#ifndef __OAMLTRACK_H__
#define __OAMLTRACK_H__

class ByteBuffer;
class oamlAudio;

class oamlTrack {
private:
	std::string name;
	int mode;

	int fadeIn;
	int fadeOut;
	int xfadeIn;
	int xfadeOut;

	int playCondSamples;

	unsigned int tailPos;

	std::vector<oamlAudio*> loopAudios;
	std::vector<oamlAudio*> randAudios;
	std::vector<oamlAudio*> condAudios;
	oamlAudio *introAudio;
	oamlAudio *endAudio;
	oamlAudio *playCondAudio;

	oamlAudio *curAudio;
	oamlAudio *tailAudio;
	oamlAudio *fadeAudio;

	int Random(int min, int max);
	oamlAudio* PickNextAudio();

	void PlayNext();
	void PlayCond(oamlAudio *audio);
	void PlayCondWithMovement(oamlAudio *audio);
	void XFadePlay();

public:
	oamlTrack();
	~oamlTrack();

	void SetName(std::string trackName) { name = trackName; }
	void SetMode(int trackMode) { mode = trackMode; }
	void SetFadeIn(int trackFadeIn) { fadeIn = trackFadeIn; }
	void SetFadeOut(int trackFadeOut) { fadeOut = trackFadeOut; }
	void SetXFadeIn(int trackXFadeIn) { xfadeIn = trackXFadeIn; }
	void SetXFadeOut(int trackXFadeOut) { xfadeOut = trackXFadeOut; }

	const char *GetNameStr() const { return name.c_str(); }
	std::string GetName() const { return name; }
	int GetFadeIn() const { return fadeIn; }
	int GetFadeOut() const { return fadeOut; }
	int GetXFadeIn() const { return xfadeIn; }
	int GetXFadeOut() const { return xfadeOut; }

	void AddAudio(oamlAudio *audio);
	void Play();
	void Stop();

	bool IsPlaying();
	void ShowPlaying();
	void ShowInfo();

	int Mix32(int sample, oamlBase *oaml);

	void SetCondition(int id, int value);
};

#endif
