/* Copyright 2021 Mads Kleemann <madskleemann@me.com> */

#pragma once

#include "quantum.h"

#define LAYOUT_69( \
  LA0, LA1, LA2, LA3, LA4, LA5, LA6,           RA1, RA2, RA3, RA4, RA5, RA6, RA7,      RA9, \
  LB0, LB2, LB3, LB4, LB5, LB6,           RB0, RB1, RB2, RB3, RB4, RB5, RB6,           RB9, \
  LC0, LC2, LC3, LC4, LC5, LC6,           RC0, RC1, RC2, RC3, RC4, RC5, RC6, RC7,      RC9, \
  LD0, LD1, LD2, LD3, LD4, LD5, LD6,           RD1, RD2, RD3, RD4, RD5, RD6,      RD8,      \
  LE0, LE1, LE3,      LE4,                          RE2,      RE4, RE5, RE6, RE7, RE8, RE9 \
  ) \
  { \
    { LA0, LA1, LA2, LA3, LA4, LA5, LA6, KC_NO, KC_NO }, \
    { LB0, KC_NO, LB2, LB3, LB4, LB5, LB6, KC_NO, KC_NO }, \
    { LC0, KC_NO, LC2, LC3, LC4, LC5, LC6, KC_NO, KC_NO }, \
    { LD0, LD1, LD2, LD3, LD4, LD5, LD6, KC_NO, KC_NO}, \
    { LE0, LE1, KC_NO, LE3, LE4, KC_NO, KC_NO, KC_NO, KC_NO }, \
    { KC_NO, RA1, RA2, RA3, RA4, RA5, RA6, RA7, KC_NO, RA9 }, \
    { RB0, RB1, RB2, RB3, RB4, RB5, RB6, KC_NO, KC_NO, RB9 }, \
    { RC0, RC1, RC2, RC3, RC4, RC5, RC6, RC7, KC_NO, RC9 }, \
    { KC_NO, RD1, RD2, RD3, RD4, RD5, RD6, KC_NO, RD8, KC_NO }, \
    { KC_NO, KC_NO, RE2, KC_NO, RE4, RE5, RE6, RE7, RE8, RE9 } \
  }
  