
all : ipc1 ipc2 ipc3 ipc4

ipc4 : ipc_producer4 ipc_consumer4

ipc_producer4 : ipc_producer4.c mysock.h
	gcc -Wall -o ipc_producer4 ipc_producer4.c

ipc_consumer4 : ipc_consumer4.c mysock.h
	gcc -Wall -o ipc_consumer4 ipc_consumer4.c

ipc3 : ipc_producer3 ipc_consumer3

ipc_producer3 : ipc_producer3.c mymsg.h
	gcc -Wall -o ipc_producer3 ipc_producer3.c

ipc_consumer3 : ipc_consumer3.c mymsg.h
	gcc -Wall -o ipc_consumer3 ipc_consumer3.c

ipc2 : ipc_producer2 ipc_consumer2

ipc_producer2 : ipc_producer2.c myshm.h
	gcc -Wall -o ipc_producer2 ipc_producer2.c

ipc_consumer2 : ipc_consumer2.c myshm.h
	gcc -Wall -o ipc_consumer2 ipc_consumer2.c

ipc1 : ipc_producer ipc_consumer

ipc_producer : ipc_producer.c myfifo.h
	gcc -Wall -o ipc_producer ipc_producer.c

ipc_consumer : ipc_consumer.c myfifo.h
	gcc -Wall -o ipc_consumer ipc_consumer.c
