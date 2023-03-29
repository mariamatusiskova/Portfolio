<?php include('zones/header.php'); ?>
<style>
	<?php include "../CSS/styleofreviews.css" ?>
</style>
<header>
	<nav>
	  <?php include('zones/nav.php'); ?>
		<button>
			<a class="button" href="reviews.php?lang=en" <?php if($lang == 'en'){?> <?php } ?>>EN</a> |
			<a class="button" href="reviews.php?lang=sk" <?php if($lang == 'sk'){?> <?php } ?>>SK</a>
		</button>
	</nav>
</header>

		<h1><?php echo $lang['reviews']; ?></h1>

		<section class="row_one">
			<div>
				<h4 class="opinion"><?php echo $lang['h4_opinion']; ?></h4>
				<p class="percent">85%</p>
			</div>
			<div>
				<h4 class="plus"><?php echo $lang['h4_advan']; ?></h4>
				<pre class="advantages"><?php echo $lang['pre_advan']; ?></pre>
			</div>
			<div>
				<h4 class="minus"><?php echo $lang['h4_disadvan']; ?></h4>
				<pre class="disadvantages"><?php echo $lang['pre_disadvan']; ?></pre>
			</div>
		</section>

		<h4 class="reviews_people"><?php echo $lang['h4_rev_people']; ?></h4>

		<article class="first">
			<h5>Matthew Osbert</h5>
			<img class="star" src="/Media/pictures/star.png" width="90px" alt="the image did not load">
			<p><?php echo $lang['p1_user']; ?></p>

			 <p><?php echo $lang['p2_user']; ?></p>

			<div class="one">
				 <ul>
				 	<li>Gorilla Glass 3</li>
				 	<li><?php echo $lang['li1']; ?></li>
				 	<li><?php echo $lang['li2']; ?></li>
				 </ul>
			</div>

			<div class="one">
				  <p><?php echo $lang['p3_user']; ?></p>

				  <ul>
				  	<li><?php echo $lang['li3']; ?></li>
				 	<li><?php echo $lang['li4']; ?></li>
				  </ul>
			</div>
		</article>

		<article class="second">
			<h5>Thomas Matula</h5>
			<img class="rating" src="/Media/pictures/rating.png" width="90px" alt="the image did not load">
			<p><?php echo $lang['p4_user']; ?></p>

			 <p><?php echo $lang['p1_user']; ?></p>

			 <div class="one">
				 <ul>
				 	<li><?php echo $lang['li5']; ?></li>
				 	<li><?php echo $lang['li6']; ?></li>
				 	<li><?php echo $lang['li7']; ?></li>
				 	<li><?php echo $lang['li8']; ?></li>
				 	<li><?php echo $lang['li9']; ?></li>
				 	<li><?php echo $lang['li10']; ?></li>
				 	<li><?php echo $lang['li11']; ?></li>
				 </ul>
			 </div>

			  <p><?php echo $lang['p3_user']; ?></p>

			  <div class="one">
				  <ul>
				  	<li><?php echo $lang['li12']; ?></li>
				 	<li><?php echo $lang['li13']; ?></li>
				  </ul>
			  </div>
			  <div class="ch">
			  	<img class="charger" src="/Media/pictures/charger.jpg" width="200px" alt="the image did not load">
			  </div>
		</article>

<?php include('zones/footer.php'); ?>