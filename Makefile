#Samuel Hasan (srh160130@utdallas.edu)
#Course: CS 3377.501
CXX = g++
CXXFLAGS = -Wall
CPPFLAGS = 

LDFLAGS =

LIBRARIES = -l cdk -lcurses

INCLUDE_PATH = /scratch/perkins/include/

LIBRARY_PATH = /scratch/perkins/lib/

PROJECTNAME = Program6

SRCS = program6.cc 

EXEC = Executable


all: $(EXEC)

clean:
	rm -f $(OBJS) *.d *~ \#* $(EXEC)

#links the files

$(EXEC): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(LDFLAGS) $(SRCS) -I $(INCLUDE_PATH) -L $(LIBRARY_PATH) $(LIBRARIES)


# Backup Target
backup:	clean
	@mkdir -p ~/backups; chmod 700 ~/backups
	@$(eval CURDIRNAME := ~/Program6/*)
	@$(eval MKBKUPNAME := ~/backups/$(PROJECTNAME).tar.gz)
	@echo
	@echo Writing Backup file to: $(MKBKUPNAME)
	@echo
	@-tar zcfv $(MKBKUPNAME) $(CURDIRNAME)
	@chmod 600 $(MKBKUPNAME)
	@echo
	@echo Done!
