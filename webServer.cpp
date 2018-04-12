tag con NOME DB e SELECT
restituisce una tabella
costruiamo una tabella HTML

Nostro tag: <sql db="scuola" query="SELECT * FROM Studenti WHERE...">

quando trova quello da spedire al client crea un file nuovo e ci scrive una table con il risultato
query restituisce un elenco di righe, su cui facciamo una fetch, chiudiamo.

Oltre a mandare la pagina HTML il webServer manda anche un file con il risultato della query,
che sarà da formattare in HTML.
