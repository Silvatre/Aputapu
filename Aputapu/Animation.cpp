#include "Animation.h"
 
namespace sf {

	Animation::Animation()
	{
		Clear();
		FramesPerSecond = 24;
		CooldownTime = 0; 
		isPlaying = true;
		isCooldown = false;
		isReverse = false;
		isLooping = true;
	}

	Animation::Animation(unsigned int setFps, double setCooldown, bool setPlay)
	{
		Clear();
		FramesPerSecond = setFps;
		CooldownTime = setCooldown;
		isPlaying = setPlay;
		isCooldown = false;
		isReverse = false;
		isLooping = true;
	}

	Animation::~Animation() 
	{}

	void Animation::Play()
	{
		isPlaying =  true;
	}

	void Animation::Stop()
	{
		isPlaying = false;
	}

	void Animation::SetFPS(unsigned int fps)
	{
		FramesPerSecond = fps;
	}

	void Animation::SetLoop(bool state)
	{
		isLooping = state;
	}

	void Animation::SetCooldown(double newCooldown)
	{
		CooldownTime = newCooldown;
	}

	Animation& Animation::operator=(const Animation& toCpy)
	{
		Clear();
		this->SetSubRect(toCpy.GetSubRect());
		Images.assign(toCpy.Images.begin(), toCpy.Images.end());
		ImageLengths.assign(toCpy.ImageLengths.begin(), toCpy.ImageLengths.end());
		isPlaying = toCpy.isPlaying;
		isCooldown = toCpy.isCooldown;
		isReverse = toCpy.isReverse;
		isLooping = toCpy.isLooping;
		CooldownTime = toCpy.CooldownTime;
		CurrentFrame = toCpy.CurrentFrame;
		CurrentImageFrame = toCpy.CurrentImageFrame;
		CurrentImage = toCpy.CurrentImage;
		FramesPerSecond = toCpy.FramesPerSecond;

		return *this;
	}

	void Animation::Reverse()
	{
		isReverse = !isReverse;
	}

	void Animation::SetReverse(bool state)
	{
		isReverse = state;
	}

    void Animation::Draw(RenderTarget& Target) {
        Target.Draw(*this);
    }

	void Animation::Cooldown()
	{
		double FrameDecrease = (Clock.GetElapsedTime() * FramesPerSecond);
		Clock.Reset();
		CurrentFrame -= FrameDecrease;
		if(CurrentFrame < 0)
		Reset();
	}

	void Animation::Reset()
	{
		isCooldown = false;
		CurrentImageFrame = 0;
		if(!isReverse)
		{
			CurrentImage = 0;
			CurrentFrame = 0;
		}
		else
		{
			CurrentImage = Images.size() - 1;
			CurrentFrame = CurrentImage;
		}
		if(!isLooping)
			Stop();
	}

    void Animation::Update() {
        // Increment the current frame within the animation that we are on
		// Update if there are any images
		if (Images.size() > 0)
		if (isCooldown)
			Cooldown();
		else
		if (isPlaying)
		{
		if (!isReverse)
		{
			double FrameIncrease = (Clock.GetElapsedTime() * FramesPerSecond);
			Clock.Reset();
			CurrentFrame += FrameIncrease;

			// And the frame of the current image that we are on
			CurrentImageFrame += FrameIncrease;
			// If we have been on the frame as long as we should of
			if (CurrentImageFrame > ImageLengths.at(CurrentImage)) 
			{
				// Go to the next image
				CurrentImage++;
				// We are now on frame 0 of this image
				CurrentImageFrame = 0;
				// If this is more frames then we have
				if (CurrentImage >= Images.size()) 
				{
					// Restart the animation
					Reset();
					if(CooldownTime > 0)
					{
						// Setting up remaining cooldown time
						CurrentFrame = CooldownTime * FramesPerSecond;
						isCooldown = true;
					}
				}
				// Change the image
				SetImage(*Images.at(CurrentImage));
			}
		}
		else UpdateReverse();
		}
    }

	void Animation::UpdateReverse()
	{
		double FrameIncrease = (Clock.GetElapsedTime() * FramesPerSecond);
		Clock.Reset();
		CurrentFrame -= FrameIncrease;
		CurrentImageFrame += FrameIncrease;
		if (CurrentImageFrame > ImageLengths.at(CurrentImage))
		{
			CurrentImage--;
			CurrentImageFrame = 0;
			if (CurrentImage <= 0) 
			{
				Reset();
				if(CooldownTime > 0)
				{
					CurrentFrame = CooldownTime * FramesPerSecond;
					isCooldown = true;
				}
			}
			SetImage(*Images.at(CurrentImage));
		}
	}

    bool Animation::AddFrame(sf::Image* NewFrame, unsigned int Length) {
        Images.push_back(NewFrame);
        ImageLengths.push_back(Length);
        if (Images.size() == 1) {
            SetSubRect(sf::Rect<int>(0,0,NewFrame->GetWidth(), NewFrame->GetHeight()));
            SetImage(*Images.at(CurrentImage));
        }
        return true;
    }

    bool Animation::InsertFrame(sf::Image* NewFrame, unsigned int Length, unsigned int Position) {
        std::vector<sf::Image*>::iterator Imgiter = Images.begin();
        std::vector<unsigned int>::iterator Intiter = ImageLengths.begin();
        if ((Position < Images.size()) && (Position >= 0)) {
            Imgiter += Position;
            Intiter += Position;
            Images.insert(Imgiter, NewFrame);
            ImageLengths.insert(Intiter, Length);
        } else {
            std::cout << "Failed to insert frame, the position(" << Position << ") is invalid\n";
            return false;
        }
        return true;
    }

    bool Animation::DeleteFrame(unsigned int Position) {
        std::vector<sf::Image*>::iterator Imgiter = Images.begin();
        std::vector<unsigned int>::iterator Intiter = ImageLengths.begin();
        if ((Position < Images.size()) && (Position >= 0)) {
            Imgiter += Position;
            Intiter += Position;
            Images.erase(Imgiter);
            ImageLengths.erase(Intiter);
        } else {
            std::cout << "Failed to delete frame, the position(" << Position << ") is invalid\n";
            return false;
        }
        return true;
    }

    void Animation::Clear() {
        Images.clear();
        ImageLengths.clear();
        CurrentFrame = 0;
        CurrentImageFrame = 0;
        CurrentImage = 0;
    }

    sf::Image* Animation::GetFrame(unsigned int Position) {
        if ((Position < Images.size()) && (Position >= 0)) {
            return Images.at(Position);
        } else {
            std::cout << "Failed to get frame, the position(" << Position << ") is invalid\n";
            return NULL;
        }
    }

}