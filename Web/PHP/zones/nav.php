<?php include "organization.php"; ?>
<img class="logo" src="/Media/pictures/mm2.png" alt="logo" width = "40" height = "40"> 
<ul class="blocks">
	<li><a class="<?php echo (basename($_SERVER['PHP_SELF'])=="moto_g6_plus.php")?"active":""?>" href="moto_g6_plus.php"><?php echo $lang['home']; ?></a></li>
	<li><a class="<?php echo (basename($_SERVER['PHP_SELF'])=="specifications.php")?"active":""?>" href="specifications.php"><?php echo $lang['specifications']; ?></a></li>
	<li><a class="<?php echo (basename($_SERVER['PHP_SELF'])=="features.php")?"active":""?>" href="features.php"><?php echo $lang['features']; ?></a></li>
	<li><a class="<?php echo (basename($_SERVER['PHP_SELF'])=="apps.php")?"active":""?>" href="apps.php"><?php echo $lang['apps']; ?></a></li>
	<li><a class="<?php echo (basename($_SERVER['PHP_SELF'])=="buy.php")?"active":""?>" href="buy.php"><?php echo $lang['buy']; ?></a></li>
	<li><a class="<?php echo (basename($_SERVER['PHP_SELF'])=="reviews.php")?"active":""?>" href="reviews.php"><?php echo $lang['reviews'];?></a></li>
	<li><a class="<?php echo (basename($_SERVER['PHP_SELF'])=="contact.php")?"active":""?>" href="contact.php"><?php echo $lang['contact'];?></a></li>
</ul>