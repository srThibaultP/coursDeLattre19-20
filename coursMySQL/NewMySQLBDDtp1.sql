-- MySQL dump 10.17  Distrib 10.3.22-MariaDB, for debian-linux-gnueabihf (armv8l)
--
-- Host: localhost    Database: BASE_SNIR
-- ------------------------------------------------------
-- Server version	10.3.22-MariaDB-0+deb10u1

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `LISTECLASSE`
--

/*DROP TABLE IF EXISTS `LISTECLASSE`;*/                                         /*Supression de la table lors de l'importation (sa ne fusionera pas les BDD)*/
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
/*CREATE TABLE `LISTECLASSE` (*/                                                /*Création de la BDD avec les mêmes paramètres qu'à la question 6*/
/*  `Id` int(11) DEFAULT NULL,*/
/*  `NOM` varchar(20) DEFAULT NULL,*/
/*  `Prénom` varchar(20) DEFAULT NULL,*/
/*  `datenaissance` date DEFAULT NULL,*/
/*  `option` varchar(2) DEFAULT NULL*/
/*) ENGINE=InnoDB DEFAULT CHARSET=latin1;*/
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `LISTECLASSE`
--

LOCK TABLES `LISTECLASSE` WRITE;                                                /*Bloque l'écriture de la table*/
/*!40000 ALTER TABLE `LISTECLASSE` DISABLE KEYS */;
INSERT INTO `LISTECLASSE` VALUES (4,'BLANCHET','Dimitri','1999-07-19','IR'),(5,'CADEAU','Clément','1999-04-25','EC'),(6,'CHAILLOU','Francois-Célestin','1998-10-26','IR'); /*Ecrit les nouvelles données*/
/*!40000 ALTER TABLE `LISTECLASSE` ENABLE KEYS */;
UNLOCK TABLES;                                                                  /*Débloque l'écriture de la table*/
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2020-03-05 14:17:33
