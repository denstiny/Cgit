cc:
	g++ ./main/main.cpp ./src/Cgit.cpp -v -w -g -o cgit
install:
	@sudo cp -uf cgit /usr/local/bin/cgit
	@sudo chmod +x /usr/local/bin/cgit
	@mkdir ~/.config/Cgit
	@cp -u ./src/Cgit.json ~/.config/Cgit/
uinstall:
	@sudo rm -rf /usr/local/bin/cgit
	@rm -fr ~/.config/Cgit

