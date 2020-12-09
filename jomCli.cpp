int main(int argv, char **argc)
{

/* cream socketul */
  if ((sd = socket (AF_INET, SOCK_STREAM, 0)) == -1)
    {
      perror ("Eroare la socket().\n");
      return errno;
    }

  /* umplem structura folosita pentru realizarea conexiunii cu serverul */
  /* familia socket-ului */
  server.sin_family = AF_INET;
  /* adresa IP a serverului */
  server.sin_addr.s_addr = inet_addr(argv[1]);
  /* portul de conectare */
  server.sin_port = htons (port);

  /* ne conectam la server */
  if (connect (sd, (struct sockaddr *) &server,sizeof (struct sockaddr)) == -1)
    {
      perror ("[client]Eroare la connect().\n");
      return errno;
    }

  //trimitem numele la server
  if (write (sd, msg, 100) <= 0)
    {
      perror ("[client]Eroare la write() spre server.\n");
      return errno;
    }

  //vedem daca primim o bila de la server
     (apel blocant pina cind serverul raspunde) */
  if (read (sd, bila, sizeof(int)) < 0)
    {
      perror ("[client]Eroare la read() de la server.\n");
      return errno;
    }

//daca clientul primeste o bila atunci va trimite mesaj de avertisment prin server
  if (bila == 1)
  {
        while(true)
                {
                        msg = "avertisment"
                        if(write(sd. "avertisment", sizeof(msg)))
                        printf("Eroare la avertizare");
						sleep(3);
                }
  }
  /* inchidem conexiunea, am terminat */
  close (sd);

}
