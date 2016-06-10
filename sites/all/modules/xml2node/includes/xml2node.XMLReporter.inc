<?php

/**
 * @file
 * collects messages about import
 *
 * @TODO not in use yet - possible extension - creating uniform message logger
 *
 * @author Jan Azzati - Previon AG
 * @author blueminds.eu
 */
class XMLReporter {

  private static $instance;

  // just to make constructor private
  private function __construct() {}

  /**
   * Simple factory method
   * @static
   * @return XMLReporter
   */
  public static function getReporter() {
    if (!isset(self::$instance)) {
      $className = __CLASS__;
      self::$instance = new $className;
    }
    return self::$instance;
  }

  /**
   * Set message to session
   * @param $message
   * @param $type
   * @param null $file
   * @return void
   */
  public function setMessage($message, $type, $file = NULL) {
    $_SESSION['xml2node']['reporter'][] = array(
      'message' => $message,
      'type' => $type,
      'file' => $file,
    );
  }

  /**
   * Get all messages
   * @return array
   */
  public function getMessages() {
    return $_SESSION['xml2node'];
  }

  /**
   * Erase all messages
   * @return void
   */
  public function eraseMessages() {
    unset($_SESSION['xml2node']);
  }

  public function __destruct() {
    unset($_SESSION['xml2node']);
  }
}

