<?php include('zones/header.php'); ?>
<style>
	<?php include "../CSS/styleoffeatures.css" ?>
</style>

		<header>
			<nav>
				<?php include('zones/nav.php'); ?>
				<button>
					<a class="button" href="features.php?lang=en" <?php if($lang == 'en'){?> <?php } ?>>EN</a> |
					<a class="button" href="features.php?lang=sk" <?php if($lang == 'sk'){?> <?php } ?>>SK</a>
				</button>
			</nav>
		</header>

		<h1 class="heading"><?php echo $lang['features']; ?></h1>
		
		<section class="first_row">
			<div class="google_voice">
				<h2><strong><?php echo $lang['h2_one']; ?></strong></h2>
					<h3><?php echo $lang['h3_four']; ?></h3>
					    <p><?php echo $lang['p_google_voice_one']; ?></p>
					<h3><?php echo $lang['h3_five']; ?></h3>
						<p><?php echo $lang['p_google_voice_two']; ?></p>
					 <img class="microphone" src="/Media/pictures/microphone.png" alt="the image did not load" width="73" height="73">
			</div>

			<img class="phonefeatures" src="/Media/pictures/phonefeatures.jpg" alt="the image did not load" width="417" height="563">
		</section>

		<section class="second_row">
			<div class="control">
				<h2><strong><?php echo $lang['h2_two']; ?></strong></h2>
					<h3><?php echo $lang['h3_one']; ?></h3>
					 	<p><strong><?php echo $lang['p_home']; ?></strong><?php echo $lang['p_h']; ?></p>
				 	 	<p><strong><?php echo $lang['p_back']; ?></strong><?php echo $lang['p_b']; ?></p>
			 	 	 	<p><strong><?php echo $lang['p_recents']; ?></strong><?php echo $lang['p_r']; ?></p>
		 	 	 	 	<p><strong><?php echo $lang['p_lock']; ?></strong><?php echo $lang['p_l']; ?></p>
		 	 	 	 	<p><strong><?php echo $lang['p_google_assistant']; ?></strong><?php echo $lang['p_g']; ?></p>
		 	  	<img class="interactivity" src="/Media/pictures/interactivity.png" alt="the image did not load" width="68" height="68">
			</div>

			<div class="picturein">
				<h2><strong><?php echo $lang['h2_three']; ?></strong></h2>
					<p><?php echo $lang['p_one']; ?></p>
				<img class="smartphone" src="/Media/pictures/smartphone.png" alt="the image did not load" width="150">
			</div>
		</section>

		<section class="third_row">
			<div class="lock">
				<h2><strong><?php echo $lang['h2_four']; ?></strong></h2>
					<h3><?php echo $lang['h3_two']; ?></h3>
						<p><strong><?php echo $lang['p_swipe']; ?></strong><?php echo $lang['p_s']; ?></p>
						<p><strong><?php echo $lang['p_pattern']; ?></strong><?php echo $lang['p_p']; ?></p>
						<p><strong><?php echo $lang['p_pin']; ?></strong><?php echo $lang['p_pin_p']; ?></p>
						<p><strong><?php echo $lang['p_password']; ?></strong><?php echo $lang['p_pas']; ?></p>
						<p><strong><?php echo $lang['p_fingerprint']; ?></strong><?php echo $lang['p_f']; ?></p>
						<p><strong><?php echo $lang['p_face']; ?></strong><?php echo $lang['p_fa']; ?></p>
				<img  class="safety" src="/Media/pictures/unlocked.png" alt="the image did not load" width="50" height="50">
			</div>

			<div class="moto">
				<h2><strong><?php echo $lang['h2_five']; ?></strong></h2>
					<h3><?php echo $lang['h3_three']; ?></h3>
						<p><strong><?php echo $lang['p_key']; ?></strong><?php echo $lang['p_moto_k']; ?></p>
					 	<p><strong><?php echo $lang['p_actions']; ?></strong><?php echo $lang['p_moto_a']; ?></p>
					 	<p><strong><?php echo $lang['p_display']; ?></strong><?php echo $lang['p_moto_d']; ?></p>
				 	 	<p><strong><?php echo $lang['p_voice']; ?></strong><?php echo $lang['p_moto_v']; ?></p>
		 		<img class="key" src="/Media/pictures/key.png" alt="the image did not load" width="50" height="50">
			</div>
		</section>
<?php include('zones/footer.php'); ?>