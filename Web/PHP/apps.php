<?php include('zones/header.php'); ?>
<style>
	<?php include "../CSS/styleofapps.css" ?>
	<?php include "../CSS/image.css" ?>
</style>

<header>
	<nav>
	  <?php include('zones/nav.php'); ?>
		<button>
			<a class="button" href="apps.php?lang=en" <?php if($lang == 'en'){?> <?php } ?>>EN</a> |
			<a class="button" href="apps.php?lang=sk" <?php if($lang == 'sk'){?> <?php } ?>>SK</a>
		</button>
	</nav>
</header>

		<h1><?php echo $lang['apps']; ?></h1>

		<div class="row_one">
			<section>
				<h4 class="lens"><?php echo $lang['h4_one']; ?></h4>
				<pre><?php echo $lang['pre_google_lens']; ?></pre>
				<img class="motogif" src="/Media/pictures/moto_1.gif" alt="the image did not load" width="150">
			</section>

			<section>
				<p class="p1"><?php echo $lang['p_screen']; ?></p>
				<video class="screen" controls="controls" preload="video" loop="loop" width="200">
					<source src="/Media/videos/screen.mp4" type="video/mp4" alt="the video did not load">
				</video>
			</section>

			<section>
				<h4 class="chrome"><?php echo $lang['h4_two']; ?></h4>
				<p class="p4"><?php echo $lang['p_browser']; ?></p>
				<img class="chromegif" src="/Media/pictures/moto2.gif" lt="the image did not load" width="150">
			</section>
		</div>

		<div class="row_two">
			<section>
				<h4 class="camera"><?php echo $lang['h4_three']; ?></h4>
				<p class="p9"><?php echo $lang['p_camera']; ?></p>
				<img class="camerasrc" src="/Media/pictures/camera.jpeg" alt="the image did not load" width="500" height="260">
			</section>

			<section>
				<h4 class="videocamera"><?php echo $lang['h4_four']; ?></h4>
				<p class="p2"><?php echo $lang['p_video']; ?></p> 
				<video class="videocameramp4" controls="controls" preload="video" loop="loop" width="500">
					<source src="/Media/videos/videocamera.MP4" type="video/mp4" alt="the video did not load">
				</video>
			</section>
		</div>

		<div class="row_three">
			<section>
				<h4 class="play"><?php echo $lang['h4_five']; ?></h4>
				<p class="p3"><?php echo $lang['p_play']; ?></p>
			</section>

			<section>
				<h4 class="gmail"><?php echo $lang['h4_six']; ?></h4>
				<p class="p5"><?php echo $lang['p_gmail']; ?></p>
			</section>

			<section>
				<h4 class="maps"><?php echo $lang['h4_seven']; ?></h4>
				<p class="p6"><?php echo $lang['p_maps']; ?></p>
			</section>

			<section>
				<h4 class="drive"><?php echo $lang['h4_eight']; ?></h4>
				<p class="p7"><?php echo $lang['p_drive']; ?></p>
			</section>
		</div>

		<h4 class="ring"><?php echo $lang['h4_nine']; ?></h4>

		<div class="sound_one">
			<audio class="moto" preload="audio" controls="controls">
				<source src="/Media/audio/moto.mp3" type="audio/mp3" alt="the audio did not load">
			</audio>
			<audio class="pyxis" preload="audio" controls="controls">
				<source src="/Media/audio/pyxis.mp3" type="audio/mp3" alt="the audio did not load">
			</audio>
			<audio class="argon" preload="audio" controls="controls">
				<source src="/Media/audio/argon.mp3" type="audio/mp3" alt="the audio did not load">
			</audio>
		</div>
		<div class="sound_two">
			<audio class="beep" preload="audio" controls="controls">
				<source src="/Media/audio/beep-beep-beep_alarm.mp3" type="audio/mp3" alt="the audio did not load">
			</audio>
			<audio class="privitanie" preload="audio" controls="controls"> 
				<source src="/Media/audio/privítanie.mp3" type="audio/mp3" alt="the audio did not load">
			</audio>
		</div>

		<article>
			<h4 class="gallery"><?php echo $lang['h4_ten']; ?></h4>

			<section class="row">
			<?php
				$file = glob("./Media/images/*");

				foreach($file as $image){
					echo "<section class = 'dynamic'><img class = 'image' src='".$image."'></section>";
				}
			?>
			</section>

		</article>
<?php include('zones/footer.php'); ?>