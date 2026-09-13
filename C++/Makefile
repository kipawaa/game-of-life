main:
	cmake -B build -S .
	cmake --build build
	./build/src/game_of_life

.PHONY: test
test:
	cmake -B build
	cmake --build build
	./build/test/gol_tests
