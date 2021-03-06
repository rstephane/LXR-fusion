/*
 * distortion.h
 *
 *  Created on: 11.04.2012
 * ------------------------------------------------------------------------------------------------------------------------
 *  Copyright 2013 Julian Schmidt
 *  Julian@sonic-potions.com
 * ------------------------------------------------------------------------------------------------------------------------
 *  This file is part of the Sonic Potions LXR drumsynth firmware.
 * ------------------------------------------------------------------------------------------------------------------------
 *  Redistribution and use of the LXR code or any derivative works are permitted
 *  provided that the following conditions are met:
 *
 *       - The code may not be sold, nor may it be used in a commercial product or activity.
 *
 *       - Redistributions that are modified from the original source must include the complete
 *         source code, including the source code for all components used by a binary built
 *         from the modified sources. However, as a special exception, the source code distributed
 *         need not include anything that is normally distributed (in either source or binary form)
 *         with the major components (compiler, kernel, and so on) of the operating system on which
 *         the executable runs, unless that component itself accompanies the executable.
 *
 *       - Redistributions must reproduce the above copyright notice, this list of conditions and the
 *         following disclaimer in the documentation and/or other materials provided with the distribution.
 * ------------------------------------------------------------------------------------------------------------------------
 *   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 *   INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 *   DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 *   SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 *   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE
 *   USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ------------------------------------------------------------------------------------------------------------------------
 */


#ifndef DISTORTION_H_
#define DISTORTION_H_
//--------------------------------------------------
#include "stm32f4xx.h"
//--------------------------------------------------
typedef struct DistStruct
{
	float shape;
	float inv_shape;
}Distortion;
//--------------------------------------------------
void setDistortionShape(Distortion *dist, uint8_t shape);
//--------------------------------------------------
void calcDistBlock(const Distortion *dist, int16_t* buf, const uint8_t size);
//--------------------------------------------------
float distortion_calcSampleFloat(const Distortion *dist, float x);

// rstephane : DELAY
void calcDelayBlock(float delay, int16_t* buf, const uint8_t size);
void calcOTOFxBlockOLD(uint8_t maskType, int16_t* buf,const uint8_t size);
void calcOTOFxBlock(uint8_t maskType, int16_t* buf,const uint8_t size,uint8_t otoAmount);
void calcAlienWahFxBlock(uint8_t freq,uint8_t startphase,uint8_t fb,uint8_t delay, int16_t* buf,const uint8_t size);

#define FILTER_GAIN 					0x70ff
void moog_perform(uint8_t moogFilterType,int8_t cutOff,int8_t resonance, int16_t* buf,const uint8_t size);
//--------------------------------------------------
#endif /* DISTORTION_H_ */
