#include "operation_CES.h"
#include "CES_SPI_support.h"


char SPI_special(const char CS) {
    if (SPI_D2S(CS, SPI_readM_2(CS)) == 100) {
        fa1();
        fa1();
        fa1();
        fa1();
        fa1();
        fa1();
        fa1();
        fa1();
        fa1();
        SPI_RET_2();
        return 1;
    }
    return 0;
}

/*
戻り値-2：err
    　100：特殊型
    　0以上：CE_LISTの配列番号
 */
signed char SPI_D2S(const char SPI_CS, const char SPI_DATA) {
    char str_SPI[3] = {'\0', '\0', '\0'};
    int i;
    if (SPI_DATA == 9) {
        //特殊型
        str_SPI[0] = '@';
        return 100;
    } else if (SPI_DATA == 0) {
        str_SPI[0] = '@';
        return 0;
    } else {
        if (SPI_DATA <= 13 && SPI_DATA >= 10) {
            switch (SPI_CS) {
                case 0:
                    switch (SPI_DATA) {
                        case 10:
                            str_SPI[0] = 'M';
                            str_SPI[1] = '\'';
                            break;
                        case 11:
                            str_SPI[0] = 'S';
                            str_SPI[1] = '\0';
                            break;
                        case 12:
                            str_SPI[0] = 'M';
                            str_SPI[1] = '\0';
                            break;
                        case 13:
                            str_SPI[1] = '\'';
                            str_SPI[0] = 'S';
                            break;
                    }
                    break;
                case 1:
                    switch (SPI_DATA) {
                        case 10:
                            str_SPI[0] = 'M';
                            str_SPI[1] = '\'';
                            break;
                        case 11:
                            str_SPI[0] = 'E';
                            str_SPI[1] = '\0';
                            break;
                        case 12:
                            str_SPI[0] = 'M';
                            str_SPI[1] = '\0';
                            break;
                        case 13:
                            str_SPI[1] = '\'';
                            str_SPI[0] = 'E';
                            break;
                    }
                    break;
                case 2:
                    switch (SPI_DATA) {
                        case 10:
                            str_SPI[0] = 'S';
                            str_SPI[1] = '\0';
                            break;
                        case 11:
                            str_SPI[0] = 'E';
                            str_SPI[1] = '\'';
                            break;
                        case 12:
                            str_SPI[0] = 'S';
                            str_SPI[1] = '\'';
                            break;
                        case 13:
                            str_SPI[1] = '\0';
                            str_SPI[0] = 'E';
                            break;
                    }

                    break;
                case 3:
                    switch (SPI_DATA) {
                        case 10:
                            str_SPI[0] = 'M';
                            str_SPI[1] = '\0';
                            break;
                        case 11:
                            str_SPI[0] = 'E';
                            str_SPI[1] = '\0';
                            break;
                        case 12:
                            str_SPI[0] = 'M';
                            str_SPI[1] = '\'';
                            break;
                        case 13:
                            str_SPI[1] = '\'';
                            str_SPI[0] = 'E';
                            break;
                    }

                    break;
                case 4:
                    switch (SPI_DATA) {
                        case 10:
                            str_SPI[0] = 'S';
                            str_SPI[1] = '\'';
                            break;
                        case 11:
                            str_SPI[0] = 'E';
                            str_SPI[1] = '\0';
                            break;
                        case 12:
                            str_SPI[0] = 'S';
                            str_SPI[1] = '\0';
                            break;
                        case 13:
                            str_SPI[1] = '\'';
                            str_SPI[0] = 'E';
                            break;
                    }
                    break;
                case 5:
                    switch (SPI_DATA) {
                        case 10:
                            str_SPI[0] = 'M';
                            str_SPI[1] = '\'';
                            break;
                        case 11:
                            str_SPI[0] = 'S';
                            str_SPI[1] = '\'';
                            break;
                        case 12:
                            str_SPI[0] = 'M';
                            str_SPI[1] = '\0';
                            break;
                        case 13:
                            str_SPI[1] = '\0';
                            str_SPI[0] = 'S';
                            break;
                    }
                    break;
            }
        } else {
            if (SPI_DATA > 4) {
                str_SPI[1] = '\0';
            } else {
                str_SPI[1] = '\'';
            }
            if (SPI_CS == 2) {
                if (SPI_DATA > 4) {
                    str_SPI[1] = '\'';
                } else {
                    str_SPI[1] = '\0';
                }
            }
            switch (SPI_CS) {
                case 0:
                    str_SPI[0] = SPI0_D2S0(1 + (SPI_DATA - 1) % 4);
                    break;
                case 1:
                    str_SPI[0] = SPI1_D2S0(1 + (SPI_DATA - 1) % 4);
                    break;
                case 2:
                    str_SPI[0] = SPI2_D2S0(1 + (SPI_DATA - 1) % 4);
                    break;
                case 3:
                    str_SPI[0] = SPI3_D2S0(1 + (SPI_DATA - 1) % 4);
                    break;
                case 4:
                    str_SPI[0] = SPI4_D2S0(1 + (SPI_DATA - 1) % 4);
                    break;
                case 5:
                    str_SPI[0] = SPI5_D2S0(1 + (SPI_DATA - 1) % 4);
                    break;
                default:
                    return -2;
                    break;
            }
        }
        if (str_SPI[0] == '@') {
            return -2;
        }
        for (i = 0; i < CE_LIST_COUNT; i++) {
            if (str_cmp_const(str_SPI, CE_LIST[i].name) == 0) {
                return i;
            }
        }
    }
    return -2;
}

char SPI0_D2S0(const char SPI_DATA) {
    switch (SPI_DATA) {
        case 1:
            return 'B';
        case 2:
            return 'R';
        case 3:
            return 'F';
        case 4:
            return 'L';
        default:
            return '@';
    }
}

char SPI1_D2S0(const char SPI_DATA) {
    switch (SPI_DATA) {
        case 1:
            return 'U';
        case 2:
            return 'R';
        case 3:
            return 'D';
        case 4:
            return 'L';
        default:
            return '@';
    }
}

char SPI2_D2S0(const char SPI_DATA) {
    switch (SPI_DATA) {
        case 1:
            return 'U';
        case 2:
            return 'B';
        case 3:
            return 'D';
        case 4:
            return 'F';
        default:
            return '@';
    }
}

char SPI3_D2S0(const char SPI_DATA) {
    switch (SPI_DATA) {
        case 1:
            return 'U';
        case 2:
            return 'L';
        case 3:
            return 'D';
        case 4:
            return 'R';
        default:
            return '@';
    }
}

char SPI4_D2S0(const char SPI_DATA) {
    switch (SPI_DATA) {
        case 1:
            return 'U';
        case 2:
            return 'B';
        case 3:
            return 'D';
        case 4:
            return 'F';
        default:
            return '@';
    }
}

char SPI5_D2S0(const char SPI_DATA) {
    switch (SPI_DATA) {
        case 1:
            return 'F';
        case 2:
            return 'R';
        case 3:
            return 'B';
        case 4:
            return 'L';
        default:
            return '@';
    }
}
