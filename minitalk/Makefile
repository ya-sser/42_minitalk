SNAME = server
CNAME = client

all : $(SNAME) $(CNAME)

$(SNAME) : server.c
	@gcc -Wall -Wextra -Werror server.c utils.c -o $(SNAME)

$(CNAME) : client.c
	@gcc -Wall -Werror -Wextra client.c utils.c -o $(CNAME)

clean :
	@rm -f $(SNAME) $(CNAME)

fclean : clean

re : clean all
