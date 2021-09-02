<?php
    $firstname= $_POST['firstname'];
    $lastname= $_POST['lastname'];
    $email= $_POST['email'];
    $message= $_POST['message'];

    //Database connection
    $conn = new mysqli('localhost','Jesse','Jesse.2030.','test');
    if($conn->connect_error){
    	die('Connection Failed : '.$conn->connect_error);
    	    }else{
    	    	$stmt = $conn->prepare("insert into reviews(firstname ,lastname , email, message)values(?, ?, ?, ?");
    	    	$stmt->bind_param("ssss",$firstname, $lastname, $email, $message);
    	    	$stmt->execute();
    	    	echo "Registration Successful....";
    	    	$stmt->close();
    	    	$conn->close();
    	    }
?>