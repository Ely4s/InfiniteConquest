//
// Created by Elyas EL IDRISSI on 28/02/2021.
//

#ifndef INFINITECONQUEST_ANIMABLE_H
#define INFINITECONQUEST_ANIMABLE_H

class Animable
{

public:
	
	virtual void goToNextFrame();
	
	virtual void goToNextStep();
	
	virtual void goToFirstStep();
	
	virtual bool isAtFirstStep() const;
	
	virtual bool isAtLastStep() const;
	
	virtual float getSecondPerFrame() const;
	
	virtual void setSecondPerFrame(float secondPerFrame);
	
	virtual int getFrameNbr() const;
	
	virtual void setFrameNbr(int frameNbr);
	
protected:
	
	virtual float getFrameIt() const;
	virtual void setFrameIt(float frameIt);
	
private:
	
	float frameIt = 0;
	int frameNbr = 0;
	float secondPerFrame = 1;
	
};


#endif //INFINITECONQUEST_ANIMABLE_H
