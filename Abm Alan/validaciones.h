
float getFloat(char msj[]);

/** \brief Pide un entero y lo devuelve.
 *
 * \param mensaje para el usuario.
 * \param
 * \return devuelve el numero entero.
 *
 */

int function_getInt(char msj[] );

/** \brief Pide un caracter y lo devuelve.
 *
 * \param mensaje para el usuario.
 * \param
 * \return Devuelve el caracter ingresado.
 *
 */

char function_getChar(char msj[]);

/** \brief Verifica que todos los valores de la string sean numericos.
 *
 * \param string a verificar.
 * \param
 * \return devuelve 1 si verifica, sino 0.
 *
 */

int function_esNum(char str[]);

/** \brief Verifica que la string ingresada contenga solo letras.
 *
 * \param String a verificar.
 * \param
 * \return Devuelve 1 si verifica, sino 0.
 *
 */

int function_esSoloLetras(char str[]);

/** \brief Verifica si la string es alfanumerica.
 *
 * \param String a verificar.
 * \param
 * \return Devuelve 1 si verifica, sino 0.
 *
 */

int function_esAlfaNumerico(char str[]);

/** \brief Pide una cadena de caracteres.
 *
 * \param mensaje para el usuario.
 * \param lo que ingresa el usuario.
 * \return No devuelve.
 *
 */

void function_getString (char msj[],char input[]);

/** \brief Verifica que la string ingresada sean solo letras y la devuelve (la copia a input).
 *
 * \param mensaje para el usuario.
 * \param lo que ingresa el usuario.
 * \return 1 si verifica, sino 0.
 *
 */

int function_getStringLetras(char msj[],char input[]);

/** \brief Verifica que la string contenga solo numeros, un guion y la devuelve (la copia a input).
 *
 * \param mensaje para el usuario.
 * \param lo que ingresa el usuario.
 * \return 1 si verifica, sino 0.
 *
 */

 int function_esTelefono(char msj[],char str[]);

 /** \brief verifica que el sexo ingresado sea M o F.
  *
  * \param mensaje para el usuario.
  * \param  lo que ingresa el usuario.
  * \return 1 si verifica, sino 0.
  *
  */

  int function_ValidaSexo(char msj[],char input[]);

/** \brief Verifica que la string contenga solo numeros y la devuelve (la copia a input).
 *
 * \param mensaje para el usuario.
 * \param lo que ingresa el usuario.
 * \return 1 si verifica, sino 0.
 *
 */

  int function_getStringNumeros(char msj[],char input[]);

