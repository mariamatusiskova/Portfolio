<?php include('zones/header.php'); ?>
<style>
	<?php include "../CSS/styleofcontact.css" ?>
</style>

<header>
	<nav>
	  <?php include('zones/nav.php'); ?>
		<button>
			<a class="button" href="contact.php?lang=en" <?php if($lang == 'en'){?> <?php } ?>>EN</a> |
			<a class="button" href="contact.php?lang=sk" <?php if($lang == 'sk'){?> <?php } ?>>SK</a>
		</button>
	</nav>
</header>

		<h1><?php echo $lang['h1_contact']; ?></h1>

		<section>
			<table>
				<th><?php echo $lang['th1_name']; ?></th>
				<td>Mária Matušisková</td>
			</table>
			<table>
				<th><?php echo $lang['th2_phone']; ?></th>
				<td><a href="tel: +1-202-555-0141"></a>+1-202-555-0141</td>
			</table>
			<table>
				<th>Email:</th>
				<td><a href="mailto": scuby@zane.pro></a>scubscuby@zane.pro</td>
			</table>
		</section>

		<form action="" method="post">
		<h3><?php echo $lang['h3_ask']; ?></h3>
		 <ul>
		  <li>
		    <label for="name"><?php echo $lang['th1_name']; ?></label>
		    <input type="text" id="name" name="user_name">
		  </li>
		  <li>
		    <label for="mail">E-mail:</label>
		    <input type="email" id="mail" name="user_email">
		  </li>
		  <li>
		    <label for="msg"><?php echo $lang['label_mes']; ?></label>
		    <textarea cols="35" rows="5" id="msg" name="user_message" ></textarea>
		  </li>
		 </ul>
		 <input class="button" type="submit" name="send" value="send">
		</form>

		<h3><?php echo $lang['h3_comments']; ?></h3><br>

		<?php 

			$name = "";
			if(isset($_POST['user_name'])){
			    $name = $_POST['user_name'];
			}
			$email = "";
			if(isset($_POST['user_email'])){
			    $email = $_POST['user_email'];
			}
			$message = "";
			if(isset($_POST['user_message'])){
			    $message = $_POST['user_message'];
			}
			$send = "";
			if(isset($_POST['send'])){
			    $send = $_POST['send'];
			}

			if ($send) {
				$fw = fopen("data.txt", "a+");
				fwrite($fw, "<div><p><b>$name</b></p><p><u>$email</u></p><p>$message</p></div>");
				fclose($fw);

				$fr = fopen("data.txt", "r+t");

				while (!feof($fr)) {
					echo fread($fr, 1024);
				}
				fclose($fr);
			}
			else {
				$fr = fopen("data.txt", "r+t");

				while (!feof($fr)) {
					echo fread($fr, 1024);
				}
				fclose($fr);
			}

		?>

<?php include('zones/footer.php'); ?>