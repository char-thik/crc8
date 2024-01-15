#include "crc8.h"

Crc8::Crc8(uint8_t poly)
{
    init(poly);
}

void Crc8::init(uint8_t poly)
{
    for (uint16_t index = 0; index < 256; ++index)
    {
        uint8_t crc = index;
        for (int shift = 0; shift < 8; ++shift)
        {
            crc = (crc << 1) ^ ((crc & 0x80) ? poly : 0);
        }
        _lut[index] = crc & 0xff;
    }
}

uint8_t Crc8::calc(uint8_t *data, uint8_t len)
{
    uint8_t crc = 0;
    while (len--)
    {
        crc = _lut[crc ^ *data++];
    }
    return crc;
}