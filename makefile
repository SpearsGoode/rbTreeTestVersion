all: test phase2 final gauntlet
	@echo -e "\n"

gauntlet: final
	@echo -e "\n	  compiling RBTgauntlet.cpp"
	@g++ RBTgauntlet.cpp	-Wall -std=c++17 -o rbtGauntlet.o
	@echo -e "	  RBTgauntlet.cpp compiled"
	@echo -e "	    running rbtGauntlet \n"
	@echo -e "--------------------------------------------\n"
	@./rbtGauntlet.o
	@echo -e "\n--------------------------------------------"
	@echo -e "\n	    gauntlet completed"

final: phase2
	@echo -e "\n	  compiling FinalTests.cpp"
	@g++ FinalTests.cpp -std=c++17 -o final.o
	@echo -e "	  FinalTests.cpp compiled"
	@echo -e "	       running final \n"
	@echo -e "--------------------------------------------\n"
	@echo -e "	  ---------------------\n"
	@echo -e "	     running test 1"
	@echo -e "	-------------------------\n"
	@./final.o 1
	@echo -e "	  ---------------------\n"
	@echo -e "	     running test 2"
	@echo -e "	-------------------------\n"
	@./final.o 2
	@echo -e "	  ---------------------\n"
	@echo -e "	     running test 3"
	@echo -e "	-------------------------\n"
	@./final.o 3
	@echo -e "	  ---------------------\n"
	@echo -e "	     running test 4"
	@echo -e "	-------------------------\n"
	@./final.o 4
	@echo -e "	  ---------------------\n"
	@echo -e "	     running test 5"
	@echo -e "	-------------------------\n"
	@./final.o 5
	@echo -e "	  ---------------------\n"
	@echo -e "	     running test 6"
	@echo -e "	-------------------------\n"
	@./final.o 6
	@echo -e "\n--------------------------------------------"
	@echo -e "\n	     final completed"

phase2: test
	@echo -e "\n	  compiling Phase2Main.cpp"
	@g++ Phase2Main.cpp	-Wall -std=c++17 -o phase2.o
	@echo -e "	  Phase2Main.cpp compiled"
	@echo -e "	      running phase2 \n"
	@echo -e "--------------------------------------------\n"
	@./phase2.o
	@echo -e "\n--------------------------------------------"
	@echo -e "\n	      phase2 completed"

test: RBTree
	@echo -e "\n	  compiling RBTreeTest.cpp"
	@g++ RBTreeTest.cpp -Wall	-std=c++17 -o rbtest.o
	@echo -e "	  RBTreeTest.cpp compiled"
	@echo -e "	      running rbtest \n"
	@echo -e "--------------------------------------------\n"
	@./rbtest.o
	@echo -e "--------------------------------------------"
	@echo -e "\n	      test completed"


RBTree:
	@clear
	@echo -e "\n	      Begin Compilation"
