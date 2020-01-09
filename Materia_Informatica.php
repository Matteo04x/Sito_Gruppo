<!-- 
4INB 16-11-2019

Matteo Spiga
Leone Pietro
Alberto Lerose
Federico Fedeli

Pagina Materia Informatica -->

<!DOCTYPE html>

<html lang="it">

    <head>
	
	    <title>Materia Informatica</title>
	    <meta charset="UTF-8">
	    <link rel="stylesheet" type="text/css" href="Css\Orientamento.css">
		<link rel="shortcut icon" href="Img\Logo_Montani.png" />

    </head>
	
	<body>

    	<nav>
            <a href="index.php">Home</a>
            <div class="Menu">
                <button class="Barra" onclick="window.location.href='Articolazione_Informatica.php'">Informatica</button>
                <div class="Contenuto">
                    <a href="Materia_Informatica.php">Informatica</a>
                    <a href="Materia_Sistemi_e_Reti.php">Sistemi e Reti</a>
	                <a href="Materia_T.P.S.I.T..php">T.P.S.I.T.</a>
                    <a href="Materia_Telecomunicazioni.php">Telecomunicazioni</a>
                </div>
            </div>
			<a href="Articolazione_Telecomunicazioni.php">Telecomunicazioni</a>
        </nav>

	    <!-- Immagine Sfondo Centrale -->
        <img src="Img\Materia_Informatica.jpg" alt="Materia_Informatica" class="Immagine">
	
	    <!-- Paragrafo -->
	    <section class="Riquadro" style="margin:50px 0;margin-left:150px">

	    	<!-- Articolo all'interno del quale sono presenti delle informazioni riguardo alla materia informatica -->
		    <article class="Distanza_Immagini" style="text-align:left">

    	    	<h2><b>Informatica</b></h2> <!-- Titolo -->
    	       	<h4>
                    Nella materia informatica, viene trattata l'analisi e la risoluzione di problemi. 
                    Il perito informatico, per svolgere tale mansione, affianca all'algoritmo, prontamente architettato,
					tecnologie idonee a tal scopo; in modo da generalizzarne la risoluzione.
                    In questa materia verranno approfondite le tecniche di programmazione,
					e verranno affrontati linguaggi di programmazione, di basso e di alto livello; come C, C++ e JAVA.
                </h4>
	    	</article>

	    	<article class="Distanza_Immagini">
                    <img src="Img\Icona_Informatica.png" alt="Icona_Informatica" style="width:50%"/> <!-- Immagine -->
	    	</article>
	    </section>
		
		<div class="Box" >
	        <h3 class="Intestazione">Programma Visitatori Scuola Aperta</h3> <!-- Titolo -->
            <h4>Il Seguente Programma permette di registrare i visitatori </br>della scuola I.T.T. G. e M. Montani nelle giornate di scuola aperta.
			    Dopo aver inserito in elenco almeno un visitatore il programma permetterà di visualizzare tutti i visitatori per una determinata
                città o provincia. Inoltre il programma consentirà di modificare le informazioni di un visitatore o di cancellare un visitatore dall'elenco  
                inserendo il suo codice.				
	    	</h4>
	    	<button onclick="return Programma_Visitatori();">Eseguimi!</button>
    	</div>
	
    	<div class="Box" >
	        <div class="Riquadro" >
	            <h3 class="Intestazione">Programma Rubrica Telefonica</h3> <!-- Titolo -->
            	<h4>Il Seguente Programma permette di andare a registrare dei contatti all'interno di una rubrica telefonica.
				    Una volta inserito almeno un contatto, il programma permetterà di visualizzare il nome di un determinato contatto 
				    inserendo il suo numero telefonico e viceversa, inoltre il programma permette anche la visualizzazione di tutti i numeri telefonici 
                    di tutti i contatti residenti in una determinata città, o di tutti i contatti con una simpatia minore o uguale ad una inserita dall'utente.
					Il programma permette infine la rimozione di un contatto dalla rubrica telefonica inserendo il suo nome.
				</h4>
	        	<button onclick="return Programma_Rubrica();">Eseguimi!</button>
	    	</div>
	    </div>
	
	    <div class="Box" >
	        <h3 class="Intestazione">Programma Crittografia di Cesare</h3> <!-- Titolo -->
        	<h4>
             	Il Seguente Programma permette inserendo una frase ad esempio la parola "ciao" e scegliendo il numero di traslazioni 
				di cui traslare ogni carattere ad esempio 3, di ottenere una frase crittografata,in questo caso ogni carattere della 
                parola "ciao" verrà traslato di 3 caratteri ottenendo quindi la parola crittografata "fldr".				
	    	</h4>
	    	<button onclick="return Crittografia_di_Cesare();">Eseguimi!</button>
    	</div>

        <!-- Piè di pagina -->
        <footer class="Footer">
			<div class="Logo">
				<img src="Img\Logo.png" class="Immagine"> <!--Immagine del Montani-->
			</div>

			<div class="Credits"> <!--Contenitore per i creatori del sito-->
				<div class="Title">Sviluppato da :</div>
			
					<!--Divisione in più campi per gestire gli spazi-->
					<div class="Campo">Matteo Spiga</div>
					<div class="Campo">Pietro Leone</div>
					<div class="Campo">Federico Fedeli</div>
					<div class="Campo">Alberto Lerose</div>
			
			</div>

			<div class="Contacts"> <!--Contenitore per i contatti-->
				<div class="Title">Vieni a trovarci o contattaci</div>
			
					<!--Divisione in più campi per gestire gli spazi-->
					<div class="Campo"><u><a href="https://goo.gl/maps/bMNuCJCrdcFVxeBTA" target="_blank" class="Indirizzo">Via Girolamo 7</a></u></div>
					<div class="Campo">0734 622632</div>
			
			</div>

			<div class="Social"> <!--Contenitore per i link ai social-->
				<div class="Title">Seguici sui nostri social</div>
			
					<!--Le immagini sono dei png resi cliccabili-->
					<a href="https://it-it.facebook.com/istitutomontani" target="_blank"> <img src="Img\Facebook.png" class="Icona"> </a> <a href="https://instagram.com" target="_blank"> <img src="Img\Instagram.png" class="Icona"> </a> <a href="https://twitter.com" target="_blank"> <img src="Img\Twitter.png" class="Icona"> </a>
			</div>
		</footer>
		
		<script>
			//Codice per il richiamo di un file php 
			function Programma_Rubrica() {
		 		Richiesta(
 			    	'Programmi/Programmi_Informatica/Programma_Rubrica.php', // URL per il file PHP
		  	    	Output,         // Gestisce la riuscita della domanda
 		 	    	Trova_Errori    // Gestisce eventuali errori
 		 		);
 			 	return false;
			}
	
			function Programma_Visitatori() {
 				Richiesta(
 			    	'Programmi/Programmi_Informatica/Programma_Visitatori.php', // URL per il file PHP
 		 	    	Output,         // Gestisce la riuscita della domanda
 		 	    	Trova_Errori    // Gestisce eventuali errori
 		 		);
 			 	return false;
			}
		
			function Crittografia_di_Cesare() {
 				Richiesta(
 			    	'Programmi/Programmi_Informatica/Crittografia_di_Cesare.php', // URL per il file PHP
 		 	    	Output,         // Gestisce la riuscita della domanda
  			    	Trova_Errori    // Gestisce eventuali errori
 	 			);
	 	 	return false;
			}
		
			//Funzione per rilevare errori
			function Trova_Errori() {
 			    var container = document.getElementById('output');
 			    	container.innerHTML = 'Errore!';
			}
		
			//Gestisce la risposta, aggiunge il codice html
			function Output(responseText) {
 			    var container = document.getElementById('output');
			   		container.innerHTML = responseText;
			}
		
			// Funzione per la gestione dei vari browser
			function Richiesta(url, success, error) {
 				var req = false;
  				try{
  	 		    	// Per la maggiorparte dei browser
   		    		req = new XMLHttpRequest();
   		 		} 
				catch (e){
    		   		// Per Internet Explorer
    	  			try{
    	   	    		req = new ActiveXObject("Msxml2.XMLHTTP");
    	   	 		} 
					catch(e) {
         	  		    // Prova una versione piu' vecchia del browser
        	    		try{
       		    	     	req = new ActiveXObject("Microsoft.XMLHTTP");
       		    	 	} 
						catch(e) {
       		        	 	return false;
       		     		}
      		  		}
    	    	}
			
    			if (!req) return false;
    			if (typeof success != 'function') success = function () {};
    			if (typeof error!= 'function') error = function () {};
    				req.onreadystatechange = function(){
        			if(req.readyState == 4) {
       	    			return req.status === 200 ? 
      	    	      	success(req.responseText) : error(req.status);
      	  			}
    			}
    			req.open("GET", url, true);
    			req.send(null);
    			return req;
			}
		</script>
		
    </body>
</html>