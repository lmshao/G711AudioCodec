//
// Created by liming on 2022/8/11.
// https://github.com/freeswitch/spandsp/blob/master/src/spandsp/g711.h
//

#ifndef _G711_WRAPPER_H
#define _G711_WRAPPER_H

#include <stdint.h>
#include <string.h>
#include "g711.h"

class G711 {
public:
    enum G711_TYPE {
        G711_ALAW,
        G711_ULAW
    };

    // pcm s16le -> g711 alaw/ulaw u8
    static int encode(G711_TYPE type, int16_t *decoded, int nSamples, uint8_t *encoded);

    // g711 alaw/ulaw u8 -> pcm s16le
    static int decode(G711::G711_TYPE type, uint8_t *encoded, int nSamples, int16_t *decoded);

};

#endif //_G711_WRAPPER_H
