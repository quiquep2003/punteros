u0_a349@termux:~/punteros/$ a=$(ls ./); \
for i in $a; do if [[ -f $i ]]; then \
ls -lh $i | \
awk '{ printf("%-6s %-10s\n", $5, $9)}'; \
fi; done
5.8K   func01
1.1K   func01.c
5.8K   func02
1.1K   func02.c
7.0K   func03
610    func03.c
7.8K   func04
2.4K   func04.c
5.8K   func11
682    func11.c
5.8K   func12
406    func12.c
388    hist20250915.sh
u0_a349@termux:~/punteros/$
