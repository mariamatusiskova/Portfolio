<?php include('zones/header.php'); ?>
<style>
	<?php include "../CSS/styleofbuy.css" ?>
</style>
<header>
	<nav>
	  <?php include('zones/nav.php'); ?>
		<button>
			<a class="button" href="buy.php?lang=en" <?php if($lang == 'en'){?> <?php } ?>>EN</a> |
			<a class="button" href="buy.php?lang=sk" <?php if($lang == 'sk'){?> <?php } ?>>SK</a>
		</button>
	</nav>
</header>

		<h1><?php echo $lang['buy']; ?></h1>

		<div class="row_one">
			<img class="blue" src="/Media/pictures/mobile_blue2.jpg" width="500px" alt="the image did not load">

		
			<section class="buy_link">
				<table>
					<tr>
						<th><?php echo $lang['th1']; ?></th>
						<th><?php echo $lang['th2']; ?></th>
					</tr>
					<tr>
						<td><a target="_blank" class="ebay" href="https://www.ebay.co.uk/p/18020399927">Ebay</a></td>
						<td>£84.99</td>
					</tr>
				</table>

				<table>
					<tr>
						<th><?php echo $lang['th3']; ?></th>
					</tr>
					<tr>
						<td><a target="_blank" class="heureka" href="https://mobilne-telefony.heureka.sk/motorola-moto-g6-plus-4gb-64gb-single-sim/#section">Heureka</a></td>
					</tr>
					<tr>
						<td><a target="_blank" class="kimovil" href="https://www.kimovil.com/en/where-to-buy-motorola-moto-g6-plus">Kimovil</a></td>
					</tr>
				</table>
			</section>
		</div>

		<footer>
			<p class="infotext">
				&copy; Copyright. Moto G6 Plus. All Rights Reserved.<br>
				Created by Maria Matusiskova 2021
			</p>
		</footer>

	</body>
</html>