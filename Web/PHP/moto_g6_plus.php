<?php include('zones/header.php'); ?>
<style>
	<?php include "../CSS/styleofthewebsite.css" ?>
</style>
<header>
	<nav>
	  <?php include('zones/nav.php'); ?>
		<button>
			<a class="button" href="moto_g6_plus.php?lang=en" <?php if($lang == 'en'){?> <?php } ?>>EN</a> |
			<a class="button" href="moto_g6_plus.php?lang=sk" <?php if($lang == 'sk'){?> <?php } ?>>SK</a>
		</button>
	</nav>
</header>


		<h1 class="heading">Moto G6 Plus</h1>

		<div>
			<img src="/Media/pictures/red.png" alt="the image did not load" width="329" height="493"> 
			<img src="/Media/pictures/phone_screen2.png" alt="the image did not load" width="235" height="452">
			<pre class="text" style="text-align: center;">
				<?php echo $lang['basic_text']; ?>
			</pre>
		</div>

		<video class="vid" controls = "controls" preload="video" loop = "loop" width="600">
			<source src="/Media/videos/doplacu.mp4" type="video/mp4" alt="the video did not load">
		</video>

		<section>
			<article>
				<a href="specifications.php">
				<img class="orange" src="/Media/pictures/phone_orange.jpg" alt="the image did not load" width="274" height="288">
				<h2 class="specifications"><?php echo $lang['h_specifications']; ?></h2>
				<p class="sp"><?php echo $lang['p_specifications']; ?></p>
			</article>
			<article>
				<a href="features.php">
				<img class="bubbles" src="/Media/pictures/dark_b2.jpg" alt="the image did not load" width="432" height="288">
				<h2 class="functions"><?php echo $lang['h_features']; ?></h2>
				<p class="pf"><?php echo $lang['p_features']; ?></p>
			</article>
		</section>

<?php include('zones/footer.php'); ?>