#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/master_main_ver5_9.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/master_main_ver5_9.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=master/CES_SPI_support.c master/EEROM_WR.c master/main.c master/master_SPI.c master/operation_CES.c master/SerialLED_PIC18F25K22.c master/solution_CES.c master/sound.c master/animation.c master/IDA_CES.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/master/CES_SPI_support.p1 ${OBJECTDIR}/master/EEROM_WR.p1 ${OBJECTDIR}/master/main.p1 ${OBJECTDIR}/master/master_SPI.p1 ${OBJECTDIR}/master/operation_CES.p1 ${OBJECTDIR}/master/SerialLED_PIC18F25K22.p1 ${OBJECTDIR}/master/solution_CES.p1 ${OBJECTDIR}/master/sound.p1 ${OBJECTDIR}/master/animation.p1 ${OBJECTDIR}/master/IDA_CES.p1
POSSIBLE_DEPFILES=${OBJECTDIR}/master/CES_SPI_support.p1.d ${OBJECTDIR}/master/EEROM_WR.p1.d ${OBJECTDIR}/master/main.p1.d ${OBJECTDIR}/master/master_SPI.p1.d ${OBJECTDIR}/master/operation_CES.p1.d ${OBJECTDIR}/master/SerialLED_PIC18F25K22.p1.d ${OBJECTDIR}/master/solution_CES.p1.d ${OBJECTDIR}/master/sound.p1.d ${OBJECTDIR}/master/animation.p1.d ${OBJECTDIR}/master/IDA_CES.p1.d

# Object Files
OBJECTFILES=${OBJECTDIR}/master/CES_SPI_support.p1 ${OBJECTDIR}/master/EEROM_WR.p1 ${OBJECTDIR}/master/main.p1 ${OBJECTDIR}/master/master_SPI.p1 ${OBJECTDIR}/master/operation_CES.p1 ${OBJECTDIR}/master/SerialLED_PIC18F25K22.p1 ${OBJECTDIR}/master/solution_CES.p1 ${OBJECTDIR}/master/sound.p1 ${OBJECTDIR}/master/animation.p1 ${OBJECTDIR}/master/IDA_CES.p1

# Source Files
SOURCEFILES=master/CES_SPI_support.c master/EEROM_WR.c master/main.c master/master_SPI.c master/operation_CES.c master/SerialLED_PIC18F25K22.c master/solution_CES.c master/sound.c master/animation.c master/IDA_CES.c


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/master_main_ver5_9.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F25K22
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/master/CES_SPI_support.p1: master/CES_SPI_support.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/master" 
	@${RM} ${OBJECTDIR}/master/CES_SPI_support.p1.d 
	@${RM} ${OBJECTDIR}/master/CES_SPI_support.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/master/CES_SPI_support.p1 master/CES_SPI_support.c 
	@-${MV} ${OBJECTDIR}/master/CES_SPI_support.d ${OBJECTDIR}/master/CES_SPI_support.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/master/CES_SPI_support.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/master/EEROM_WR.p1: master/EEROM_WR.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/master" 
	@${RM} ${OBJECTDIR}/master/EEROM_WR.p1.d 
	@${RM} ${OBJECTDIR}/master/EEROM_WR.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/master/EEROM_WR.p1 master/EEROM_WR.c 
	@-${MV} ${OBJECTDIR}/master/EEROM_WR.d ${OBJECTDIR}/master/EEROM_WR.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/master/EEROM_WR.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/master/main.p1: master/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/master" 
	@${RM} ${OBJECTDIR}/master/main.p1.d 
	@${RM} ${OBJECTDIR}/master/main.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/master/main.p1 master/main.c 
	@-${MV} ${OBJECTDIR}/master/main.d ${OBJECTDIR}/master/main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/master/main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/master/master_SPI.p1: master/master_SPI.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/master" 
	@${RM} ${OBJECTDIR}/master/master_SPI.p1.d 
	@${RM} ${OBJECTDIR}/master/master_SPI.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/master/master_SPI.p1 master/master_SPI.c 
	@-${MV} ${OBJECTDIR}/master/master_SPI.d ${OBJECTDIR}/master/master_SPI.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/master/master_SPI.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/master/operation_CES.p1: master/operation_CES.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/master" 
	@${RM} ${OBJECTDIR}/master/operation_CES.p1.d 
	@${RM} ${OBJECTDIR}/master/operation_CES.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/master/operation_CES.p1 master/operation_CES.c 
	@-${MV} ${OBJECTDIR}/master/operation_CES.d ${OBJECTDIR}/master/operation_CES.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/master/operation_CES.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/master/SerialLED_PIC18F25K22.p1: master/SerialLED_PIC18F25K22.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/master" 
	@${RM} ${OBJECTDIR}/master/SerialLED_PIC18F25K22.p1.d 
	@${RM} ${OBJECTDIR}/master/SerialLED_PIC18F25K22.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/master/SerialLED_PIC18F25K22.p1 master/SerialLED_PIC18F25K22.c 
	@-${MV} ${OBJECTDIR}/master/SerialLED_PIC18F25K22.d ${OBJECTDIR}/master/SerialLED_PIC18F25K22.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/master/SerialLED_PIC18F25K22.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/master/solution_CES.p1: master/solution_CES.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/master" 
	@${RM} ${OBJECTDIR}/master/solution_CES.p1.d 
	@${RM} ${OBJECTDIR}/master/solution_CES.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/master/solution_CES.p1 master/solution_CES.c 
	@-${MV} ${OBJECTDIR}/master/solution_CES.d ${OBJECTDIR}/master/solution_CES.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/master/solution_CES.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/master/sound.p1: master/sound.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/master" 
	@${RM} ${OBJECTDIR}/master/sound.p1.d 
	@${RM} ${OBJECTDIR}/master/sound.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/master/sound.p1 master/sound.c 
	@-${MV} ${OBJECTDIR}/master/sound.d ${OBJECTDIR}/master/sound.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/master/sound.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/master/animation.p1: master/animation.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/master" 
	@${RM} ${OBJECTDIR}/master/animation.p1.d 
	@${RM} ${OBJECTDIR}/master/animation.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/master/animation.p1 master/animation.c 
	@-${MV} ${OBJECTDIR}/master/animation.d ${OBJECTDIR}/master/animation.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/master/animation.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/master/IDA_CES.p1: master/IDA_CES.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/master" 
	@${RM} ${OBJECTDIR}/master/IDA_CES.p1.d 
	@${RM} ${OBJECTDIR}/master/IDA_CES.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/master/IDA_CES.p1 master/IDA_CES.c 
	@-${MV} ${OBJECTDIR}/master/IDA_CES.d ${OBJECTDIR}/master/IDA_CES.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/master/IDA_CES.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/master/CES_SPI_support.p1: master/CES_SPI_support.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/master" 
	@${RM} ${OBJECTDIR}/master/CES_SPI_support.p1.d 
	@${RM} ${OBJECTDIR}/master/CES_SPI_support.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/master/CES_SPI_support.p1 master/CES_SPI_support.c 
	@-${MV} ${OBJECTDIR}/master/CES_SPI_support.d ${OBJECTDIR}/master/CES_SPI_support.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/master/CES_SPI_support.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/master/EEROM_WR.p1: master/EEROM_WR.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/master" 
	@${RM} ${OBJECTDIR}/master/EEROM_WR.p1.d 
	@${RM} ${OBJECTDIR}/master/EEROM_WR.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/master/EEROM_WR.p1 master/EEROM_WR.c 
	@-${MV} ${OBJECTDIR}/master/EEROM_WR.d ${OBJECTDIR}/master/EEROM_WR.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/master/EEROM_WR.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/master/main.p1: master/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/master" 
	@${RM} ${OBJECTDIR}/master/main.p1.d 
	@${RM} ${OBJECTDIR}/master/main.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/master/main.p1 master/main.c 
	@-${MV} ${OBJECTDIR}/master/main.d ${OBJECTDIR}/master/main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/master/main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/master/master_SPI.p1: master/master_SPI.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/master" 
	@${RM} ${OBJECTDIR}/master/master_SPI.p1.d 
	@${RM} ${OBJECTDIR}/master/master_SPI.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/master/master_SPI.p1 master/master_SPI.c 
	@-${MV} ${OBJECTDIR}/master/master_SPI.d ${OBJECTDIR}/master/master_SPI.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/master/master_SPI.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/master/operation_CES.p1: master/operation_CES.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/master" 
	@${RM} ${OBJECTDIR}/master/operation_CES.p1.d 
	@${RM} ${OBJECTDIR}/master/operation_CES.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/master/operation_CES.p1 master/operation_CES.c 
	@-${MV} ${OBJECTDIR}/master/operation_CES.d ${OBJECTDIR}/master/operation_CES.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/master/operation_CES.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/master/SerialLED_PIC18F25K22.p1: master/SerialLED_PIC18F25K22.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/master" 
	@${RM} ${OBJECTDIR}/master/SerialLED_PIC18F25K22.p1.d 
	@${RM} ${OBJECTDIR}/master/SerialLED_PIC18F25K22.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/master/SerialLED_PIC18F25K22.p1 master/SerialLED_PIC18F25K22.c 
	@-${MV} ${OBJECTDIR}/master/SerialLED_PIC18F25K22.d ${OBJECTDIR}/master/SerialLED_PIC18F25K22.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/master/SerialLED_PIC18F25K22.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/master/solution_CES.p1: master/solution_CES.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/master" 
	@${RM} ${OBJECTDIR}/master/solution_CES.p1.d 
	@${RM} ${OBJECTDIR}/master/solution_CES.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/master/solution_CES.p1 master/solution_CES.c 
	@-${MV} ${OBJECTDIR}/master/solution_CES.d ${OBJECTDIR}/master/solution_CES.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/master/solution_CES.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/master/sound.p1: master/sound.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/master" 
	@${RM} ${OBJECTDIR}/master/sound.p1.d 
	@${RM} ${OBJECTDIR}/master/sound.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/master/sound.p1 master/sound.c 
	@-${MV} ${OBJECTDIR}/master/sound.d ${OBJECTDIR}/master/sound.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/master/sound.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/master/animation.p1: master/animation.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/master" 
	@${RM} ${OBJECTDIR}/master/animation.p1.d 
	@${RM} ${OBJECTDIR}/master/animation.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/master/animation.p1 master/animation.c 
	@-${MV} ${OBJECTDIR}/master/animation.d ${OBJECTDIR}/master/animation.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/master/animation.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/master/IDA_CES.p1: master/IDA_CES.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/master" 
	@${RM} ${OBJECTDIR}/master/IDA_CES.p1.d 
	@${RM} ${OBJECTDIR}/master/IDA_CES.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/master/IDA_CES.p1 master/IDA_CES.c 
	@-${MV} ${OBJECTDIR}/master/IDA_CES.d ${OBJECTDIR}/master/IDA_CES.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/master/IDA_CES.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/master_main_ver5_9.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=dist/${CND_CONF}/${IMAGE_TYPE}/master_main_ver5_9.X.${IMAGE_TYPE}.map  -D__DEBUG=1  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto        $(COMPARISON_BUILD) -Wl,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -o dist/${CND_CONF}/${IMAGE_TYPE}/master_main_ver5_9.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	@${RM} dist/${CND_CONF}/${IMAGE_TYPE}/master_main_ver5_9.X.${IMAGE_TYPE}.hex 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/master_main_ver5_9.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=dist/${CND_CONF}/${IMAGE_TYPE}/master_main_ver5_9.X.${IMAGE_TYPE}.map  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     $(COMPARISON_BUILD) -Wl,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -o dist/${CND_CONF}/${IMAGE_TYPE}/master_main_ver5_9.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
