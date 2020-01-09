<!-- 
4INB 16-11-2019

Matteo Spiga
Leone Pietro
Alberto Lerose
Federico Fedeli

Pagina principale -->

<!DOCTYPE html>

<html lang="it">

    <head>
	
	    <title>Home</title>
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
      	<img src="Img\Informatica.jpg" alt="Articolazione" class="Immagine">

		<section class="Riquadro" style="margin:50px 0">

			<!-- Articolo all'interno del quale sono presenti delle informazioni riguardo all'articolazione informatica -->
			<article class="Distanza_Immagini">
			    
				<h3 style="display:inline-flex;font-size:40px"><b>Informatica&nbsp;</b> <!-- Titolo -->
				    <a href="Articolazione_Informatica.php">
        	            <img  src="Img\Icona_Informatica.png" alt="Icona_Informatica" width="75" height="75" align="right"> <!-- Immagine -->
				    </a>
			    </h3>
    			
				<h4 align=left>
					Nell’articolazione <b style="display:inline-block;font-size:23px">"Informatica"</b> viene approfondita:
                    <ul style="list-style-type:none;">
					
					    <li>• L'<b class="In_Linea">Analisi</b>;</li>
						<li>• Lo <b class="In_Linea">Sviluppo</b> delle <b class="In_Linea">Applicazioni Informatiche</b>;</li>
                        <li>• La <b class="In_Linea">Comparazione</b> e la <b class="In_Linea">Progettazione</b> di Dispositivi e Strumenti Informatici;</li>
                        <li>• La <b class="In_Linea">Realizzazione</b> di <b class="In_Linea">Soluzioni Informatiche</b> a Sostegno delle Aziende.</li>
                    </ul>
					Il profilo	professionale dell’indirizzo consente l’inserimento nei processi aziendali,
					in precisi ruoli funzionali coerenti con gli obiettivi dell’impresa.
				</h4>
			</article>

			<!-- Articolo all'interno del quale sono presenti delle informazioni riguardo all'articolazione telecomunicazioni -->
			<article class="Distanza_Immagini">
			
			    <h3 style="display:inline-flex;font-size:40px"><b>Telecomunicazioni&nbsp;</b> <!-- Titolo -->
				    <a href="Articolazione_Telecomunicazioni.php">
        	            <img  src="Img\Icona_Telecomunicazioni.png" alt="Icona_Telecomunicazioni" width="75" height="75" align="right"> <!-- Immagine -->
				    </a>
			    </h3>
    			
    			<h4 align=left>
					Nell’articolazione <b style="display:inline-block;font-size:23px">"Telecomunicazioni"</b> viene approfondita:
                    <ul style="list-style-type:none;">
					    <li>• L'<b class="In_Linea">Analisi</b>;</li>
                        <li>• La <b class="In_Linea">Comparazione</b>,la <b class="In_Linea">Progettazione</b>
						      l'<b class="In_Linea">Installazione</b> e la <b class="In_Linea">Gestione</b> di 
							  Dispositivi e Strumenti Elettronici e Sistemi di Telecomunicazioni;</li>
					    <li>• Lo <b class="In_Linea">Sviluppo</b> di <b class="In_Linea">Applicazioni Informatiche</b> per Reti Locali e Servizi a Distanza.</li>
                    </ul>
					Il profilo professionale
					dell’indirizzo permette un efficace inserimento in una pluralità di contesti aziendali, con possibilità
					di approfondire maggiormente le competenze correlate alle caratteristiche delle diverse realtà
				    territoriali.
				</h4>
			</article>
		</section>
	
        <!-- Posizione su Google Maps della scuola I.T.T.S. Montani-->
        <article style="margin-bottom:20px">
            <iframe src="https://www.google.com/maps/embed?pb=!1m18!1m12!1m3!1d2909.9398347213564!2d13.734717069387859!3d43.168787066722814!2m3!1f0!2f0!3f0!3m2!1i1024!2i768!4f13.1!3m3!1m2!1s0x133211dc2f85f2d5%3A0x6d909746c3d3a230!2sVia%20Joyce%20Lussu%2C%2063900%20Fermo%20FM!5e0!3m2!1sit!2sit!4v1573298655253!5m2!1sit!2sit" width="100%" height="450" frameborder="0" style="border:0;" allowfullscreen=""></iframe>   
        </article>

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

    </body>
</html>