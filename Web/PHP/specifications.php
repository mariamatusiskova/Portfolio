<?php include('zones/header.php'); ?>
<style>
	<?php include "../CSS/styleofspecifications.css" ?>
</style>
<header> 
	<nav>
	  <?php include('zones/nav.php'); ?>
		<button>
			<a class="button" href="specifications.php?lang=en" <?php if($lang == 'en'){?> <?php } ?>>EN</a> |
			<a class="button" href="specifications.php?lang=sk" <?php if($lang == 'sk'){?> <?php } ?>>SK</a>
		</button>
	</nav>
</header>

		<h1 class="heading"><?php echo $lang['specifications']; ?></h1>

		<section>
			<img class="blue" src="/Media/pictures/phone_k1.jpg" alt="the image did not load" width="329" height="478">

			
			<div class="parametres">
				<details>
					<summary><strong><?php echo $lang['summary_one']; ?></strong></summary>
						<table>
							<!-- none td -->
							<tr>
								<th><?php echo $lang['th_one']; ?></th>
								<td>Motorola</td>
							</tr>
							<tr>
								<th><?php echo $lang['th_two']; ?></th>
								<td>Android</td>
							</tr>
							<tr>
								<th><?php echo $lang['th_three']; ?></th>
								<td>Android 9.0 - Pie</td>
							</tr>
							<!-- none td -->
						</table>
				</details>
				<details>
					<summary><strong><?php echo $lang['summary_two']; ?></strong></summary>
						<table>
						    <tr>
						    	<th><?php echo $lang['th_four']; ?></th>
						    	<td>5.9 inch</td>
						    </tr>
						    <!-- none td -->
						    <tr>
						    	<th><?php echo $lang['th_five']; ?></th>
						    	<td>IPS</td>
						    </tr>
						    <tr>
						    	<th><?php echo $lang['th_six']; ?></th>
						    	<td>2160x1080</td>
						    </tr>
						    <tr>
						    	<th><?php echo $lang['th_seven']; ?></th>
						    	<td>18:9</td>
						    </tr>
						    <tr>
						    	<th><?php echo $lang['th_eight']; ?></th>
						    	<td>1</td>
						    </tr>
						    <!-- none td -->
						</table>
				</details>
				<details>
				    <summary><strong><?php echo $lang['summary_three']; ?></strong></summary>
						<table>
							<!-- none td -->
							<tr>
								<th><?php echo $lang['th_nine']; ?></th>
								<td>Qualcomm Snapdragon 630</td>
							</tr>
							<tr>
								<th><?php echo $lang['th_ten']; ?></th>
								<td>8x</td>
							</tr>
							<tr>
								<th><?php echo $lang['th_eleven']; ?>y</th>
								<td>2,2 GHz</td>
							</tr>
							<tr>
								<th><?php echo $lang['th_twelve']; ?></th>
								<td>Qualcomn Adreno 508</td>
							</tr>
							<tr>
								<th><?php echo $lang['th_thirteen']; ?></th>
								<td>4096 MB</td>
							</tr>
							<tr>
								<th><?php echo $lang['th_fourteen']; ?></th>
								<td>64GB</td>
							</tr>
							<!-- none td -->
							<tr>
								<th><?php echo $lang['th_fifteen']; ?></th>
								<td><?php echo $lang['td_yes']; ?></td>
							</tr>
						</table>
				</details>
				<details>
					<summary><strong><?php echo $lang['summary_four']; ?></strong></summary>
						<table>
							<!-- none th -->
							<tr>
								<th>Dual SIM</th>
								<td><?php echo $lang['td_yes']; ?></td>
							</tr>
							<tr>
								<th>LTE</th>
								<td><?php echo $lang['td_yes']; ?></td>
							</tr>
							<tr>
								<th>GPRS</th>
								<td><?php echo $lang['td_yes']; ?></td>
							</tr>
							<tr>
								<th>MMS</th>
								<td><?php echo $lang['td_yes']; ?></td>
							</tr>
							<tr>
								<th>Wi-fi</th>
								<td><?php echo $lang['td_yes']; ?></td>
							</tr>
							<tr>
								<th>Bluetooth</th>
								<td><?php echo $lang['td_yes']; ?></td>
							</tr>
							<!-- none td -->
							<!-- none th -->
							<tr>
								<th><?php echo $lang['th_sixteen']; ?></th>
								<td>Bluetooth 5.0</td>
							</tr>
							<!-- none td -->
							<tr>
								<th><?php echo $lang['th_seventeen']; ?></th>
								<td><?php echo $lang['td_yes']; ?></td>
							</tr>
							<!-- none th -->
							<tr>
								<th>NFC</th>
								<td><?php echo $lang['td_yes']; ?></td>
							</tr>
							<tr>
								<th>FM radio</th>
								<td><?php echo $lang['td_yes']; ?></td>
							</tr>
							<tr>
								<th>3,5mm audio jack</th>
								<td><?php echo $lang['td_yes']; ?></td>
							</tr>
							<!-- none th -->
							<tr>
								<th><?php echo $lang['th_eighteen']; ?></th>
								<td><?php echo $lang['td_yes']; ?></td>
							</tr>
						</table>
				</details>
				<details>
					<summary><strong><?php echo $lang['summary_five']; ?></strong></summary>
						<table>
							<tr>
								<th><?php echo $lang['th_nineteen']; ?></th>
								<td><?php echo $lang['td_yes']; ?></td>
							</tr>
							<tr>
								<th><?php echo $lang['th_twenty']; ?></th>
								<td><?php echo $lang['td_yes']; ?></td>
							</tr>
							<tr>
								<th><?php echo $lang['th_twentyone']; ?></th>
								<td><?php echo $lang['td_yes']; ?></td>
							</tr>
						</table>
				</details>
				<details>
					<summary><strong><?php echo $lang['summary_six']; ?></strong></summary>
						<table>
							<tr>
								<th><?php echo $lang['th_twentytwo']; ?></th>
								<td><?php echo $lang['td_yes']; ?></td>
							</tr>
							<!-- none td -->
							<tr>
								<th><?php echo $lang['th_twentythree']; ?></th>
								<td>12Mpx</td>
							</tr>
							<!-- none td -->
							<tr>
								<th><?php echo $lang['th_twentyfour']; ?></th>
								<td><?php echo $lang['td_one']; ?></td>
							</tr>
							<tr>
								<th><?php echo $lang['th_twentyfive']; ?></th>
								<td><?php echo $lang['td_yes']; ?></td>
							</tr>
							<tr>
								<th><?php echo $lang['th_twentysix']; ?></th>
								<td><?php echo $lang['td_yes']; ?></td>
							</tr>
							<tr>
								<th><?php echo $lang['th_twentyseven']; ?></th>
								<td><?php echo $lang['td_no']; ?></td>
							</tr>
							<!-- none th -->
							<tr>
								<th>HD video</th>
								<td><?php echo $lang['td_yes']; ?></td>
							</tr>
							<!-- none th -->
							<tr>
								<th><?php echo $lang['th_twentyeight']; ?></th>
								<td><?php echo $lang['td_yes']; ?></td>
							</tr>
							<!-- none td -->
							<tr>
								<th><?php echo $lang['th_twentynine']; ?></th>
								<td>8 Mpx</td>
							</tr>
							<!-- none td -->
						</table>
				</details>
				<details>
					<summary><strong><?php echo $lang['summary_seven']; ?></strong></summary>
						<table>
							<!-- none td -->
							<tr>
								<th><?php echo $lang['th_thirty']; ?></th>
								<td>3200 mAh</td>
							</tr>
							<!-- none td -->
							<tr>
								<th><?php echo $lang['th_thirtyone']; ?></th>
								<td><?php echo $lang['td_no']; ?></td>
							</tr>
							<tr>
								<th><?php echo $lang['th_thirtytwo']; ?></th>
								<td><?php echo $lang['td_no']; ?></td>
							</tr>
						</table>
				</details>
				<details>
					<summary><strong><?php echo $lang['summary_eight']; ?></strong></summary>
						<table>
							<!-- none td -->
							<tr>
								<th><?php echo $lang['th_thirtythree']; ?></th>
								<td>167 g</td>
							</tr>
							<tr>
								<th><?php echo $lang['th_thirtyfour']; ?></th>
								<td>160 mm</td>
							</tr>
							<tr>
								<th><?php echo $lang['th_thirtyfive']; ?></th>
								<td>75,5 mm</td>
							</tr>
							<tr>
								<th><?php echo $lang['th_thirtysix']; ?></th>
								<td>8 mm</td>
							</tr>
							<!-- none td -->
						</table>
				</details>
			</div>
		</section>

<?php include('zones/footer.php'); ?>