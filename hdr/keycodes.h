/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keycodes.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/23 16:23:25 by mteerlin      #+#    #+#                 */
/*   Updated: 2021/08/25 11:35:11 by mteerlin      ########   odam.nl         */
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

#  define K_DEL 65535
#  define K_HOME 65360
#  define K_END 65367
#  define K_PGUP 65365
#  define K_PGDWN 65366
# else
#  define K_A 0
#  define K_B 11
#  define K_C 8
#  define K_D 2
#  define K_E 14
#  define K_F 3
#  define K_G 5
#  define K_H 4
#  define K_I 34
#  define K_J 38
#  define K_K 40
#  define K_L 37
#  define K_M 46
#  define K_N 45
#  define K_O 31
#  define K_P 35
#  define K_Q 12
#  define K_R 15
#  define K_S 1
#  define K_T 17
#  define K_U 32
#  define K_V 9
#  define K_W 13
#  define K_X 7
#  define K_Y 16
#  define K_Z 6

#  define K_ZERO 29
#  define K_ONE 18
#  define K_TWO 19
#  define K_THREE 20
#  define K_FOUR 21
#  define K_FIVE 23
#  define K_SIX 22
#  define K_SEVEN 26
#  define K_EIGHT 28
#  define K_NINE 25

#  define K_GRAVE 50
#  define K_DASH 27
#  define K_EQL 24
#  define K_SQBO 33
#  define K_SQBC 30
#  define K_CLN 41
#  define K_QTE 39
#  define K_COMMA 43
#  define K_PERIOD 47
#  define K_SLASH 44
#  define K_BSLASH 42

#  define K_NUMLCK 71
#  define K_NUMZERO 82
#  define K_NUMONE 83
#  define K_NUMTWO 84
#  define K_NUMTHREE 85
#  define K_NUMFOUR 86
#  define K_NUMFIVE 87
#  define K_NUMSIX 88
#  define K_NUMSEVEN 89
#  define K_NUMEIGHT 91
#  define K_NUMNINE 92
#  define K_NUMDIV 75
#  define K_NUMMULT 67
#  define K_NUMSUB 78
#  define K_NUMADD 69
#  define K_NUMENTR 76
#  define K_NUMDOT 65
#  define K_NUMEQL 81   

#  define K_ESC 53
#  define K_FONE 122
#  define K_FTWO 120
#  define K_FTHREE 99
#  define K_FFOUR 118
#  define K_FFIVE 96
#  define K_FSIX 97
#  define K_FSEVEN 98
#  define K_FEIGHT 100
#  define K_FNINE 101
#  define K_FTEN 109
#  define K_FTWELVE 111

#  define K_UP 126
#  define K_DOWN 125
#  define K_LEFT 123
#  define K_RIGHT 124

#  define K_LSHFT 257
#  define K_LCTRL 256
#  define K_LALT 259
#  define K_CPSLCK 272
#  define K_TAB 48
#  define K_RSHFT 258
#  define K_RCTRL 269
#  define K_RALT 260
#  define K_ENTR 36
#  define K_BCKSPC 51

#  define K_DEL 117
#  define K_HOME 115
#  define K_END 119
#  define K_PGUP 116
#  define K_PGDWN 121
# endif
#endif