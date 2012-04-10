#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
 
namespace sf {
	class Animation : public sf::Sprite 
	{
	private:
        std::vector<sf::Image*> Images;
        std::vector<unsigned int> ImageLengths;
		sf::Clock Clock;
	protected:
		bool isCooldown;
		bool isReverse;
		bool isLooping;
		double CooldownTime;
        double CurrentFrame;
		double CurrentImageFrame;
		int CurrentImage;
		unsigned int FramesPerSecond;
	public:
        Animation();	
		Animation(unsigned int setFps, double setCooldown, bool setPlay);
        virtual ~Animation();
		void Play();
		void Stop();
        void Update();
		void UpdateReverse();
        void Draw(RenderTarget& Target);
		void SetCooldown(double newCooldown);
		void SetFPS(unsigned int fps);
		void SetReverse(bool state);
		void SetLoop(bool state);
		void Reverse();
		void Cooldown();
		virtual void Reset();	
        bool AddFrame(sf::Image* NewFrame, unsigned int Length);
        bool InsertFrame(sf::Image* NewFrame, unsigned int Length, unsigned int Position);
        bool DeleteFrame(unsigned int Position);
		bool isPlaying;
        void Clear();
        sf::Image* GetFrame(unsigned int Position);
		Animation& operator=(const Animation& toCpy);
    };
}	// Namespace sf