# //--------------------------------------- OLD COMMAND --------------------------------------------------------//

# all: compile link

# compile:
# 	g++ -Isrc/include -c main.cpp

# link:
# 	g++ main.o -o main -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system

# //--------------------------------------- NEW COMMAND SETUP --------------------------------------------------//

# Hold the specific compiler name.
codeCompiler=g++

# Hold the source, object and include folders
sourceFolder=src/cpp
objectFolder=src/obj
binFolder=src/bin
includeFolder=src/include
libFolder=src/lib

# Hold the target file name.
targetFile=$(binFolder)/game.exe

# Hold all the source files into a single variable
# We gather all the files found on thesource file directory that happen to end on the .cpp suffix.
sourceFiles=$(wildcard $(sourceFolder)/*.cpp)

# Hold all the object files into a single variable, using the names from the source files.
# We iterate over the source files and replace the .c suffix with the .o suffix.
objectFiles=$(sourceFiles:$(sourceFolder)/%.cpp=$(objectFolder)/%.o)

# Hold all compiler flags we will pass onto the compiler into a single variable.
compilerFlags=-I$(includeFolder)

# Hold all the linker flags we will use into a single variable.
linkerFlags=-L$(libFolder) -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

# //--------------------------------------- NEW COMMAND --------------------------------------------------------//

# The default rule, nicknamed 'all', will try to act on the compilation and linking rule, both of which we define later
# If desired, we could individually call either "compile", "link", or both, giving us more control on builds
all: compile link

# "Compile" calls the rule associated with our entire set of object files; each one in turn calls a special implicit rule
# That implicit rule, associated with any object file, is incorporated on Makefiles by default. We will override it later
compile: $(objectFiles)

# This particular instruction overrides the Makefile's default, implicit rule for automatically compiling object files from cpp files
# If a given source file is younger than the corresponding object file, our custom compiling command will be triggered. 
$(objectFolder)/%.o: $(sourceFolder)/%.cpp
	$(codeCompiler) $(compilerFlags) -c $^ -o $@
# By the way, "$^" refers to the depedencies of a recipe (right hand side, after the ":"); in this case, the cpp file used as input

# "Link" calls the rule associated with the target file
link: $(targetFile)

# If the object files are younger than the target file, our custom linking will occur resulting on a new target file
$(targetFile): $(objectFiles)
	$(codeCompiler) $(objectFiles) -o $(targetFile) $(linkerFlags)
# Notice that the object files could call their implicit rule, which was previously overriden by us
# However, our custom compiling command would only be triggered if a given object file is outdated or missing
# That most likely won't be the case if the "compile" command was run beforehand. Either way, missing object files won't be an issue

# Cleaning command, so the object and target files are wiped in case a fresh rebuild is desired.
# Note that because of the foward slashes  '/' on the paths, this instruction might or might not work depending on your terminal
# It didn't work with PowerShell for me, but it did work with the GitBash terminal
# Consider using a subsitution function to replace foward slashes with backward slashes '\' if your terminal doesn't support it
clean:
	rm -f $(objectFiles) $(targetFile)
# Printing command, so that the contents of set variables can be displayed. Useful for debugging
print-%  :
	@echo $* = $($*)

# Lastly, we need to avoid the existence of files named "all", "compile", "link", "clean", "print" from messing up our commands
# We can mark these commands with ".PHONY" so Makefile knows these commands are not supposed to be correlated with existing files
.PHONY: all
.PHONY: compile
.PHONY: link
.PHONY: clean
.PHONY: print-%
# This way, Makefile will understand that we named these command pre-requisites as fakes, illusions, just used for convenience