//
// Created by limin on 2022/8/11.
//

#include "g711_wrapper.h"

#include "g711.h"
#include <stdint.h>


int G711::encode(G711_TYPE type, int16_t *decoded, int nSamples, uint8_t *encoded) {
    if (nSamples < 0) {
        return -1;
    }

    if (type == G711_ALAW) {
        for (int n = 0; n < nSamples; n++) {
            encoded[n] = (uint8_t) linear_to_alaw((int) decoded[n]);
        }
    } else if (type == G711_ULAW) {
        for (int n = 0; n < nSamples; n++) {
            encoded[n] = (uint8_t) linear_to_ulaw((int) decoded[n]);
        }
    }

    return nSamples;
}

int G711::decode(G711::G711_TYPE type, uint8_t *encoded, int nSamples, int16_t *decoded) {
    if (nSamples < 0) {
        return -1;
    }

    if (type == G711_ALAW) {
        for (int n = 0; n < nSamples; n++) {
            decoded[n] = (int16_t) alaw_to_linear(encoded[n]);
        }
    } else if (type == G711_ULAW) {
        for (int n = 0; n < nSamples; n++) {
            decoded[n] = (uint8_t) alaw_to_linear(encoded[n]);
        }
    }

    return nSamples;
}
