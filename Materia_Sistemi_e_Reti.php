<!-- 
4INB 16-11-2019

Matteo Spiga
Leone Pietro
Alberto Lerose
Federico Fedeli

Pagina Materia Sistemi e Reti -->

<!DOCTYPE html>

<html lang="it">

    <head>
	
	    <title>Materia Sistemi e Reti</title>
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
        <img src="Img\Materia_Sistemi_e_Reti.jpg" alt="Materia_Sistemi_e_Reti" class="Immagine">
	
	    <!-- Paragrafo -->
	    <section class="Riquadro" style="margin:50px 0;margin-left:150px">

	    	<!-- Articolo all'interno del quale sono presenti delle informazioni riguardo alla materia sistemi e reti -->
	    	<article class="Distanza_Immagini" style="text-align:left">

    	    	<h2><b>Sistemi e Reti</b></h2> <!-- Titolo -->
				<h4>L’obiettivo della materia “Sistemi e reti ” è proprio quello di comprendere come sono fatti e come funzionano questi sistemi che spesso,
					senza rendercene conto, tutti noi usiamo nella vita di ogni giorno: non solo i personal computer, i cellulari, o le console per eseguire videogiochi,
					ma anche altri dispositivi, probabilmente meno noti ma sicuramente più diffusi come, per esempio, i microcontrollori,
					oppure le piccole e grandi reti di calcolatori o la stessa rete Internet.
				</h4>
		    </article>

	    	<article class="Distanza_Immagini">
                    <img src="Img\Icona_Sistemi_e_Reti.png" alt="Sistemi e Reti" style="width:50%"/> <!-- Immagine -->
	    	</article>
	    </section>

	    <div class="Box" >
	        <h3 class="Intestazione">Programma Indirizzo MAC</h3> <!-- Titolo -->
        	<h4>Il Seguente Programma permette inserendo un </br>Indirizzo MAC (Es. 00-0E-5C-A0-F1-2B)
			    di sapere se questo sia un Indirizzo MAC di broadcast,single o di gruppo.
            </h4>
	    	<button onclick="return Indirizzo_MAC();">Eseguimi!</button>
	    </div>
	
    	<div class="Box" >
	        <h3 class="Intestazione">Programma Codifica</h3> <!-- Titolo -->
        	<h4>Il Seguente Programma andrà codificando sulla base di una parola chiave di quattro caratteri inserita dall'utente,
			    un messaggio anch'esso preso in input, premettendo poi di visualizzare il messaggio crittografato.
    		</h4>
		
    		<button onclick="return Programma_Codifica();">Eseguimi!</button>
	    </div>
		
		<div class="Box" >
	        <div class="Riquadro" >
	            <h3 class="Intestazione">Programma Struttura di un Pacchetto</h3> <!-- Titolo -->
        	    <h4>Il Seguente Programma permette di visualizzare inserendo un numero o una stringa,il frame di un pacchetto nel formato:
				    </br>-----------------------------------------------------
                    </br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|Header|"Dati"|Checksum|
                    </br>-----------------------------------------------------
	    	    </h4>
	    	    <button onclick="return Programma_Pacchetto();">Eseguimi!</button>
	    	</div>
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
			function Programma_Pacchetto() {
		 		Richiesta(
 			    	'Programmi/Programmi_Sistemi_e_Reti/Programma_Pacchetto.php', // URL per il file PHP
		  	    	Output,         // Gestisce la riuscita della domanda
 		 	    	Trova_Errori    // Gestisce eventuali errori
 		 		);
 			 	return false;
			}
	
			function Indirizzo_MAC() {
 				Richiesta(
 			    	'Programmi/Programmi_Sistemi_e_Reti/Indirizzo_MAC.php', // URL per il file PHP
 		 	    	Output,         // Gestisce la riuscita della domanda
 		 	    	Trova_Errori    // Gestisce eventuali errori
 		 		);
 			 	return false;
			}
		
			function Programma_Codifica() {
 				Richiesta(
 			    	'Programmi/Programmi_Sistemi_e_Reti/Programma_Codifica.php', // URL per il file PHP
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