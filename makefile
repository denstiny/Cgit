cc:
	g++ ./main/main.cpp ./src/Cgit.cpp -v -w -g -o cgit
install:
	@sudo cp -u cgit /usr/bin/cgit
	@sudo chmod +x /usr/bin/cgit
	@mkdir ~/.config/Cgit
	@cp -u ./src/Cgit.json ~/.config/Cgit/
uinstall:
	@sudo rm -rf /usr/bin/cgit
	@rm -fr ~/.config/Cgit

