/*!
 * \file 		Profet_conf.h
 * \name        Profet_conf.h - pin settings for the 24V heighside PROFET(TM) shield
 * \author      Infineon Technologies AG
 * \copyright   2019 Infineon Technologies AG
 * \version     0.1.1
 * \brief 		
 * 
 * 
 * Redistribution and use in source and binary forms, with or without modification, are permitted provided that the
 * following conditions are met:
 *
 * Redistributions of source code must retain the above copyright notice, this list of conditions and the following
 * disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following
 * disclaimer in the documentation and/or other materials provided with the distribution.
 *
 * Neither the name of the copyright holders nor the names of its contributors may be used to endorse or promote
 * products derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE  FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY,OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 */

#include "Profet_conf.h"
#include "Profet.h"

void Profet::init(void)
{
    //PROFET 0 is a two channel device (BTT6030-2EKB)
    Profet0.channel0 = (ProfetChannel){FALSE, 0, 20};
    Profet0.channel1 = (ProfetChannel){FALSE, 0, 3};
    Profet0.kilis    = 2240;
    Profet0.DEN      = 2;
    Profet0.DSEL     = 21;
    Profet0.IS       = 17;

    //PROFET 1 is a two channel device (BTT6030-2EKB)
    Profet1.channel0 = (ProfetChannel){FALSE, 0, 4};
    Profet1.channel1 = (ProfetChannel){FALSE, 0, 7};
    Profet1.kilis    = 2240;
    Profet1.DEN      = 5;
    Profet1.DSEL     = 6;
    Profet1.IS       = 18;

    //PROFET 2 is a one channel device (BTT6020-1EKB)
    Profet2.channel0 = (ProfetChannel){FALSE, 0, 8};
    Profet2.kilis    = 2950;
    Profet1.DEN      = 9;
    Profet1.IS       = 19;

}

void Profet::initGPIO(ProfetStatus profet)
{
    //DEN
    pinMode(Profet.DEN,INPUT);
    digitalWrite(Profet.DEN, HIGH);

    //IN0
    pinMode(Profet.channel0.IN,INPUT);
    digitalWrite(Profet.channel0.IN, LOW);

    if (exists(Profet.DSEL))
    {
        //DSEL
        pinMode(Profet.DSEL,INPUT);
        digitalWrite(Profet.DSEL, LOW);

        //IN1
        pinMode(Profet.channel1.IN,INPUT);
        digitalWrite(Profet.channel1.IN, LOW);
    }


}