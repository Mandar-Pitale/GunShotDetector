##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=GDS
ConfigurationName      :=Debug
WorkspacePath          := "/Users/mandarpitale/Library/Application Support/codelite/GunshotDetector"
ProjectPath            := "/Users/mandarpitale/Library/Application Support/codelite/GunshotDetector/GDS"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Mandar Pitale
Date                   :=20/09/2015
CodeLitePath           :="/Users/mandarpitale/Library/Application Support/codelite"
LinkerName             :=clang
SharedObjectLinkerName :=clang -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=
PreprocessSuffix       :=.o.i
DebugSwitch            :=-gstab
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
ObjectsFileList        :="GDS.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := ar rcus
CXX      := clang++
CC       := clang
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := llvm-as


##
## User defined environment variables
##
CodeLiteDir:=/Users/mandarpitale/Downloads/codelite.app/Contents/SharedSupport/
Objects0=$(IntermediateDirectory)/src_sample.c$(ObjectSuffix) $(IntermediateDirectory)/src_mem.c$(ObjectSuffix) $(IntermediateDirectory)/main.c$(ObjectSuffix) $(IntermediateDirectory)/02-COM_COM.c$(ObjectSuffix) $(IntermediateDirectory)/03-RTC_RTC.c$(ObjectSuffix) $(IntermediateDirectory)/04-GSD_GSD.c$(ObjectSuffix) $(IntermediateDirectory)/01-NMEA_NMEA.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/src_sample.c$(ObjectSuffix): src/sample.c 
	$(CC) $(SourceSwitch) "/Users/mandarpitale/Library/Application Support/codelite/GunshotDetector/GDS/src/sample.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_sample.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_sample.c$(PreprocessSuffix): src/sample.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_sample.c$(PreprocessSuffix) "src/sample.c"

$(IntermediateDirectory)/src_mem.c$(ObjectSuffix): src/mem.c 
	$(CC) $(SourceSwitch) "/Users/mandarpitale/Library/Application Support/codelite/GunshotDetector/GDS/src/mem.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_mem.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_mem.c$(PreprocessSuffix): src/mem.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_mem.c$(PreprocessSuffix) "src/mem.c"

$(IntermediateDirectory)/main.c$(ObjectSuffix): main.c 
	$(CC) $(SourceSwitch) "/Users/mandarpitale/Library/Application Support/codelite/GunshotDetector/GDS/main.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.c$(PreprocessSuffix): main.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.c$(PreprocessSuffix) "main.c"

$(IntermediateDirectory)/02-COM_COM.c$(ObjectSuffix): src/01-APP/02-COM/COM.c 
	$(CC) $(SourceSwitch) "/Users/mandarpitale/Library/Application Support/codelite/GunshotDetector/GDS/src/01-APP/02-COM/COM.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/02-COM_COM.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/02-COM_COM.c$(PreprocessSuffix): src/01-APP/02-COM/COM.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/02-COM_COM.c$(PreprocessSuffix) "src/01-APP/02-COM/COM.c"

$(IntermediateDirectory)/03-RTC_RTC.c$(ObjectSuffix): src/01-APP/03-RTC/RTC.c 
	$(CC) $(SourceSwitch) "/Users/mandarpitale/Library/Application Support/codelite/GunshotDetector/GDS/src/01-APP/03-RTC/RTC.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/03-RTC_RTC.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/03-RTC_RTC.c$(PreprocessSuffix): src/01-APP/03-RTC/RTC.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/03-RTC_RTC.c$(PreprocessSuffix) "src/01-APP/03-RTC/RTC.c"

$(IntermediateDirectory)/04-GSD_GSD.c$(ObjectSuffix): src/01-APP/04-GSD/GSD.c 
	$(CC) $(SourceSwitch) "/Users/mandarpitale/Library/Application Support/codelite/GunshotDetector/GDS/src/01-APP/04-GSD/GSD.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/04-GSD_GSD.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/04-GSD_GSD.c$(PreprocessSuffix): src/01-APP/04-GSD/GSD.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/04-GSD_GSD.c$(PreprocessSuffix) "src/01-APP/04-GSD/GSD.c"

$(IntermediateDirectory)/01-NMEA_NMEA.c$(ObjectSuffix): src/03-COM/01-NMEA/NMEA.c 
	$(CC) $(SourceSwitch) "/Users/mandarpitale/Library/Application Support/codelite/GunshotDetector/GDS/src/03-COM/01-NMEA/NMEA.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/01-NMEA_NMEA.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/01-NMEA_NMEA.c$(PreprocessSuffix): src/03-COM/01-NMEA/NMEA.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/01-NMEA_NMEA.c$(PreprocessSuffix) "src/03-COM/01-NMEA/NMEA.c"

##
## Clean
##
clean:
	$(RM) -r ./Debug/


