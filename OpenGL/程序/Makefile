OPENGL_SRC_PATH := ./lib/opengl
MC_SRC_PATH := ./lib/mc
EXE_PATH := ./bin
CXXFLAGES := -I ./include

OPENGL_OBJ_FILES := $(OPENGL_SRC_PATH)/camera.o \
	$(OPENGL_SRC_PATH)/texture.o \
	$(OPENGL_SRC_PATH)/mesh.o \
	$(OPENGL_SRC_PATH)/shader.o \
	$(OPENGL_SRC_PATH)/model.o \
	$(OPENGL_SRC_PATH)/utilitiy.o

MC_OBJ_FILES := $(MC_SRC_PATH)/block.o \
	$(MC_SRC_PATH)/application.o


.PHONY: openglObjs mcObjs clean

openglObjs: $(OPENGL_OBJ_FILES)

mcObjs: $(MC_OBJ_FILES)

$(OPENGL_SRC_PATH)/%.o : $(OPENGL_SRC_PATH)/%.cpp
	@g++ $(CXXFLAGES) $^ -c -o $@ -g

$(MC_SRC_PATH)/%.o : $(MC_SRC_PATH)/%.cpp
	@g++ $(CXXFLAGES) $^ -c -o $@ -g

clean: 
	@echo clean all binary files...
	@$(shell powershell (del $(EXE_PATH)/*.exe))
	@$(shell powershell (del $(OPENGL_SRC_PATH)/*.o))
	@$(shell powershell (del $(MC_SRC_PATH)/*.o))
	@echo done!