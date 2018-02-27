push: push_to_hub

push_to_hub:
	git add -A
	git commit -m "Update"
	git push -u origin master

bld_a:	array.c
	gcc -o array.exe array.c
	./array.exe

bld_l:	list.c
	gcc -o list.exe list.c
	./list.c
