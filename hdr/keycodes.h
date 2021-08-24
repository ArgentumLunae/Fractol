/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keycodes.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/23 16:23:25 by mteerlin      #+#    #+#                 */
/*   Updated: 2021/08/24 18:45:31 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYCODES_H
# define KEYCODES_H
# ifdef __linux__
#  define K_A 97
#  define K_B 98
#  define K_C 99
#  define K_D 100
#  define K_E 101
#  define K_F 102
#  define K_G 103
#  define K_H 104
#  define K_I 105
#  define K_J 106
#  define K_K 107
#  define K_L 108
#  define K_M 109
#  define K_N 110
#  define K_O 111
#  define K_P 112
#  define K_Q 113
#  define K_R 114
#  define K_S 115
#  define K_T 116
#  define K_U 117
#  define K_V 118
#  define K_W 119
#  define K_X 120
#  define K_Y 121
#  define K_Z 122

#  define K_ZERO 48
#  define K_ONE 49
#  define K_TWO 50
#  define K_THREE 51
#  define K_FOUR 52
#  define K_FIVE 53
#  define K_SIX 54
#  define K_SEVEN 55
#  define K_EIGHT 56
#  define K_NINE 57

#  define K_GRAVE 96
#  define K_DASH 45
#  define K_EQL 61
#  define K_SQBO 91
#  define K_SQBC 93
#  define K_CLN 59
#  define K_QTE 39
#  define K_COMMA 44
#  define K_PERIOD 46
#  define K_SLASH 47
#  define K_BSLASH 92

#  define K_NUMLCK 65407
#  define K_NUMZERO 65438
#  define K_NUMONE 65436
#  define K_NUMTWO 65433
#  define K_NUMTHREE 65435
#  define K_NUMFOUR 65430
#  define K_NUMFIVE 65437
#  define K_NUMSIX 65432
#  define K_NUMSEVEN 65429
#  define K_NUMEIGHT 65431
#  define K_NUMNINE 65434
#  define K_NUMDIV 65455
#  define K_NUMMULT 65450
#  define K_NUMSUB 65453
#  define K_NUMADD 65451
#  define K_NUMENTR 65421
#  define K_NUMDOT 65439

#  define K_ESC 65307
#  define K_FONE 65470
#  define K_FTWO 65471
#  define K_FTHREE 65472
#  define K_FFOUR 65473
#  define K_FFIVE 65474
#  define K_FSIX 65475
#  define K_FSEVEN 65476
#  define K_FEIGHT 65477
#  define K_FNINE 65478
#  define K_FTEN 65479
#  define K_FELEVEN 65480
#  define K_FTWELVE 65481

#  define K_UP 65362
#  define K_DOWN 65364
#  define K_LEFT 65361
#  define K_RIGHT 65363

#  define K_LSHFT 65289
#  define K_LCTRL 65507
#  define K_LALT 65513
#  define K_CPSLCK 65509
#  define K_TAB	65289
#  define K_RSHFT 65506
#  define K_RCTRL 65508
#  define K_RALT 65514
#  define K_ENTR 65293
#  define K_BCKSPC 65288

#  define K_PAUSE 65299
#  define K_INSRT 65379
#  define K_DEL 65535
#  define K_HOME 65360
#  define K_END 65367
#  define K_PGUP 65365
#  define K_PGDWN 65366
# else
#  define K_A
#  define K_B
#  define K_C
#  define K_D
#  define K_E
#  define K_F
#  define K_G
#  define K_H
#  define K_I
#  define K_J
#  define K_K
#  define K_L
#  define K_M
#  define K_N
#  define K_O
#  define K_P
#  define K_Q
#  define K_R
#  define K_S
#  define K_T
#  define K_U
#  define K_V
#  define K_W
#  define K_X
#  define K_Y
#  define K_Z

#  define K_ZERO
#  define K_ONE
#  define K_TWO
#  define K_THREE
#  define K_FOUR
#  define K_FIVE
#  define K_SIX
#  define K_SEVEN
#  define K_EIGHT
#  define K_NINE

#  define K_GRAVE
#  define K_DASH
#  define K_EQL
#  define K_SQBO
#  define K_SQBC
#  define K_CLN
#  define K_QTE
#  define K_COMMA
#  define K_PERIOD
#  define K_SLASH
#  define K_BSLASH

#  define K_NUMLCK
#  define K_NUMZERO
#  define K_NUMONE
#  define K_NUMTWO
#  define K_NUMTHREE
#  define K_NUMFOUR
#  define K_NUMFIVE
#  define K_NUMSIX
#  define K_NUMSEVEN
#  define K_NUMEIGHT
#  define K_NUMNINE
#  define K_NUMDIV
#  define K_NUMMULT
#  define K_NUMSUB
#  define K_NUMADD
#  define K_NUMENTR
#  define K_NUMDOT

#  define K_ESC
#  define K_FONE
#  define K_FTWO
#  define K_FTHREE
#  define K_FFOUR
#  define K_FFIVE
#  define K_FSIX
#  define K_FSEVEN
#  define K_FEIGHT
#  define K_FNINE
#  define K_FTEN
#  define K_FELEVEN
#  define K_FTWELVE

#  define K_UP
#  define K_DOWN
#  define K_LEFT
#  define K_RIGHT

#  define K_LSHFT
#  define K_LCTRL
#  define K_LALT
#  define K_CPSLCK
#  define K_TAB
#  define K_RSHFT
#  define K_RCTRL
#  define K_RALT
#  define K_ENTR
#  define K_BCKSPC

#  define K_PAUSE
#  define K_INSRT
#  define K_DEL
#  define K_HOME
#  define K_END
#  define K_PGUP
#  define K_PGDWN
# endif
#endif