all: test phase2
	@echo -e "\n		SUCCESS!!!!!!!!!!!!!!!!!	\n"

phase2: test
	@echo -e "\n	compiling Phase2Main.cpp"
	@g++ Phase2Main.cpp	-Wall -std=c++17 -o phase2.o
	@echo -e "\n	Phase2Main.cpp compiled"
	@echo -e "\n	running phase2 \n"
	@echo -e "--------------------------------------------\n\n"
	@./phase2.o
	@echo -e "\n\n--------------------------------------------"
	@echo -e "\n	phase2 completed \n"

test: RBTree
	@echo -e "\n	compiling RBTreeTest.cpp"
	@g++ RBTreeTest.cpp -Wall	-std=c++17 -o rbtest.o
	@echo -e "\n	RBTreeTest.cpp compiled"
	@echo -e "\n	running rbtest \n"
	@echo -e "--------------------------------------------\n\n"
	# @gdb rbtest.exe
	@./rbtest.o
	@echo -e "\n\n--------------------------------------------"
	@echo -e "\n	test completed"


RBTree:
	@clear
	@echo -e "\n		Begin Compilation"
