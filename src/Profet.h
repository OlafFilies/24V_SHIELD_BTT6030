/*!
 * \file        Profet.h
 * \name        Profet.h - library for the 24V highside PROFET(TM) shield
 * \author      Infineon Technologies AG
 * \copyright   2019 Infineon Technologies AG
 * \version     0.1.1
 * \brief       
 * \details
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


#include "util/Profet_conf.h"

#ifndef PROFET_H
#define PROFET_H


class Profet
{
    public:

    /**
     * @brief 
     * 
     */
    typedef struct ProfetChannel{
        bool     on;                //!< flag to indicate if the channel is currently switched on
        uint32_t current;           //!< the load current of the channel
        int8_t   IN;                //!< input Pin to switch channel 0
    }ProfetChannel;

    /**
     * @brief 
     * 
     */
    typedef struct ProfetStatus{
        ProfetChannel channel0;
        ProfetChannel channel1;
        int8_t   DEN;               //!< Diagnosis enable PROFET. Turns diagnosis for PROFETT on or off
        int8_t   DSEL;              //!< Diagnostic select PROFET. Selects if the diagnosis of channel 0 or 1 is muxed to the IS Pin
        int8_t   IS;                //!< Sense PROFET. Current sense of PROFET
        uint16_t kilis;             //!< the kilis of the Device (ratio between load current and sense current) you get it from the Spec
    }ProfetStatus;

    ProfetStatus Profet0;
    ProfetStatus Profet1;
    ProfetStatus Profet2;

    Profet();
    ~Profet();

    /**
     * @brief 
     * 
     */
    void begin()

    /**
     * @brief 
     * 
     */
    void end()

    //! \brief initializes this object, automatically called by begin()
    void init(void);

    /**
     * @brief 
     * 
     */
    void initGPIO(ProfetStatus profet)
}

#endif