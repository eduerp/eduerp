-- phpMyAdmin SQL Dump
-- version 3.0.1.1
-- http://www.phpmyadmin.net
--
-- Host: localhost
-- Generation Time: Jun 25, 2011 at 05:29 PM
-- Server version: 5.0.51
-- PHP Version: 5.2.7

SET SQL_MODE="NO_AUTO_VALUE_ON_ZERO";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: `eduerp`
--

-- --------------------------------------------------------

--
-- Table structure for table `webapp_institution`
--
-- Creation: Jun 25, 2011 at 03:12 PM
-- Last update: Jun 25, 2011 at 03:12 PM
--

CREATE TABLE IF NOT EXISTS `webapp_institution` (
  `id` int(11) NOT NULL auto_increment,
  `name` varchar(100) NOT NULL,
  `code` varchar(32) NOT NULL,
  `secret` varchar(32) NOT NULL,
  PRIMARY KEY  (`id`),
  UNIQUE KEY `code` (`code`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1 AUTO_INCREMENT=4 ;

--
-- Dumping data for table `webapp_institution`
--

INSERT INTO `webapp_institution` (`id`, `name`, `code`, `secret`) VALUES
(1, 'UNIVERSITY A', 'UNIA', '2fd0bba6b1774ed391c1ff8467f52a5d'),
(2, 'UNIVERSITY B', 'UNIB', 'ffaedcdf6cc045cfbb220299720a79d6'),
(3, 'UNIVERSITY C', 'UNIC', '927a220e63cd42feb70ab03f43b727f3');
