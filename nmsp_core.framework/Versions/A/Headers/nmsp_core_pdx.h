#ifndef NMSP_CORE_PDX_H
#define NMSP_CORE_PDX_H

/** \file nmsp_core_pdx.h
*           
*           Nuance Mobile Application Server Resource
*
*   \section Legal_Notice Legal Notice
*
*   Copyright 2006-2011, Nuance Communications Inc. All rights reserved.      
*                                                                           
*   Nuance Communications, Inc. provides this document without representation 
*   or warranty of any kind. The information in this document is subject to   
*   change without notice and does not represent a commitment by Nuance       
*   Communications, Inc. The software and/or databases described in this      
*   document are furnished under a license agreement and may be used or       
*   copied only in accordance with the terms of such license agreement.       
*   Without limiting the rights under copyright reserved herein, and except   
*   as permitted by such license agreement, no part of this document may be   
*   reproduced or transmitted in any form or by any means, including, without 
*   limitation, electronic, mechanical, photocopying, recording, or otherwise,
*   or transferred to information storage and retrieval systems, without the  
*   prior written permission of Nuance Communications, Inc.                   
*                                                                           
*   Nuance, the Nuance logo, Nuance Recognizer, and Nuance Vocalizer are      
*   trademarks or registered trademarks of Nuance Communications, Inc. or its 
*   affiliates in the United States and/or other countries. All other         
*   trademarks referenced herein are the property of their respective owners. 
*  
*   \section Overview
*
*   This Resource provides access to Nuance Mobile Application Server(NMAS).
*   It allows the user to access the functionalities provided by NMAS
*   and drives the applications that wish to use NMAS services.<BR><BR>
*
*   See the section on NMAS in the Introduction on the
*   Main Page tab as well as the <em>Programmer's Guide</em> for detailed
*   information on NMAS and the NMAS Resource module of the SDK.
*
*/

/*
 *  Include headers for external data types required by this interface.
 */
#include <nmsp_oem/nmsp_platform.h>
#include <nmsp_core/nmsp_core_defines.h>
#include <nmsp_oem/nmsp_vector.h>

#ifdef __cplusplus
extern "C" {
#endif



/**
 * \enum NMSP_CORE_CLASS_TYPE
 *
 * \brief Defines the possible NMAS class types, which are used to identify
 *        the NMSP_NMAS_DATA.
 *
 * \note If nmsp_core_get_dictionary_class() returns \c INVALID_CLASS_TYPE,
 *       this indicates that the key is missing in the key/value pair.
 *
 * \see nmsp_core_Dictionary
 * \see NMSP_NMAS_DATA
 **/
typedef enum {
    INVALID_CLASS_TYPE  = 0x00,     /*!< Used to indicate missing key/value */
    BYTE_STRING         = 0x04,     /*!< Indicates the type is a byte string */
    NMAS_NULL           = 0x05,     /*!< Indicates that the type is NULL entry */
    NMAS_DOUBLE         = 0x06,     /*!< Indicates that the type is a DOUBLE entry */
    NMAS_BOOLEAN        = 0x07,     /*!< Indicates that the type is a BOOLEAN entry */
    SEQUENCE            = 0x10,     /*!< Indicates the type is a sequence */
    ASCII_STRING        = 0x16,     /*!< Indicates the type is an ASCII string */
    INTEGER             = 0xC0,     /*!< Indicates the type is an integer */
    UTF8_STRING         = 0xC1,     /*!< Indicates the type is a UTF8 string */
    DICTIONARY          = 0xE0      /*!< Indicates the type is a dictionary */
} NMSP_CORE_CLASS_TYPE;

/**
 * \typedef nmsp_core_Dictionary
 *
 * \brief An opaque data structure that stores data as key/value pairs.
 *   
 * This structure represents an NMAS dictionary. An entry in a  
 * dictionary consists of a key and a corresponding value.
 *
 * \see nmsp_core_create_dictionary
 * \see nmsp_core_dictionary_add
 **/
typedef struct nmsp_core_Dictionary_ nmsp_core_Dictionary;

/**
 * \typedef nmsp_core_Sequence
 *
 * \brief An opaque data structure that stores data as an indexed list.
 * 
 * This structure represents an NMAS sequence. A sequence is an indexed
 * list of data elements.
 *
 * \see nmsp_core_create_sequence
 * \see nmsp_core_sequence_add
 **/
typedef struct nmsp_core_Sequence_ nmsp_core_Sequence;

/**
 * \brief Creates an nmsp_core_Dictionary object.
 *
 * Returns a pointer to a newly allocated nmsp_core_Dictionary. If the allocation
 * fails, NULL will be returned.
 * To delete the nmsp_core_Dictionary, the function nmsp_core_delete_dictionary() must be used.
.*
 * \return      Pointer to an nmsp_core_Dictionary. If an error occurs, NULL is returned.
 **/
NMSP_CORE_EXPORT nmsp_core_Dictionary* nmsp_core_create_dictionary(void);


/**
 * \brief Adds a key/value to an nmsp_core_Dictionary.
 * This function adds a key and its corresponding value to an existing dictionary.
 *        For all value types, a copy is made.
 *
 * \param dictionary        Pointer to an nmsp_core_Dictionary.
 *                          Must not be NULL.
 *
 * \param key               Pointer to a string. This string will be inserted as the key
 *                          to the specified value.
 *                          Must not be NULL.
 *
 * \param value             Pointer to a value. Can be: char*, int*, nmsp_core_Sequence*,
 *                          or nmsp_core_Dictionary*, depending on clss (class type).
 *                          Must not be NULL.
 *
 * \param clss              nmsp_nmas_ClassTypes. This value must match whatever type is passed
 *                          in the value parameter.
 *
 * \param value_length      Length of value, in bytes. Mandatory for values of class type: BYTE_STRING,
 *                          ASCII_STRING, and UTF8_STRING.
 *                          Not mandatory for values of other class types.
 *
 * \return      NMSP_NMAS_OK if the key/value pair is inserted into the dictionary successfully.
 *              NMSP_NMAS_ERROR if an error occurs.
 *              NMSP_NMAS_OUT_OF_MEMORY if memory allocation fails.
 *
 *
 *         For example:<BR>
 *         nmsp_core_Dictionary* dict1 = nmsp_core_create_dictionary();<BR>
 *         nmsp_core_Dictionary* dict2 = nmsp_core_create_dictionary();<BR>
 *         <BR><BR>
 *         nmsp_core_dictionary_add(dict1, "KEY_A", "Hello", ASCII_STRING, 5);<BR>
 *         nmsp_core_dictionary_add(dict2, "KEY_B", "World", ASCII_STRING, 5);<BR>
 *         nmsp_core_dictionary_add(dict1, "KEY_C", dict2, DICTIONARY, sizeof(void*));<BR>
 **/
NMSP_CORE_EXPORT NMSP_CORE_STATUS nmsp_core_dictionary_add(nmsp_core_Dictionary* dictionary,
                                                           const char*           key,
                                                           const void*           value,
                                                           NMSP_CORE_CLASS_TYPE  clss,
                                                           long                  value_length);

/**
 * \brief Retrieves the keys in a nmsp_core_Dictionary.
 *
 * Returns a newly allocated nmsp_Vector containing all the keys of the specified
 * nmsp_core_Dictionary.
 * To delete the nmsp_Vector, the function nmsp_vector_destroy() must be used.
 *
 * \param dictionary        Pointer to an nmsp_core_Dictionary.
 *                          Must not be NULL.
 *
 * \return      Pointer to an nmsp_Vector. If an error occurs, NULL is returned.              
 **/
NMSP_CORE_EXPORT nmsp_Vector* nmsp_core_dictionary_get_keys(const nmsp_core_Dictionary* dictionary);


/**
 * \brief Deletes an nmsp_core_Dictionary.
 *
 * This function deletes a previously allocate nmsp_core_Dictionary.
 * \note The nmsp_core_Dictionary can be safely deleted as soon as it is passed to the
 * function that requires it (e.g.: nmsp_nmas_command_create(...),
 * nmsp_nmas_dict_param_create(...), etc.)
 *
 * Note that dictionaries can have deep structures that are
 * made up of embedded objects (sub-dictionaries), which can also contain sub-dictionaries.
 * Using the recursive parameter, you can control which objects are deleted:
 * you can delete the entire deep structure, or you can delete only the top-most structure,
 * leaving the embedded objects intact.
 *
 * \param dictionary                 Pointer to an nmsp_core_Dictionary.
 *                                   Must not be NULL.
 *
 * \param recursive                  0 - Do not recursively delete any object in the dictionary;<BR>
 *                                   1 - Recursively delete the objects of the dictionary.<BR><BR>
 *         For example:<BR>
 *         nmsp_core_Dictionary* dict1 = nmsp_core_create_dictionary();<BR>
 *         nmsp_core_Dictionary* dict2 = nmsp_core_create_dictionary();<BR>
 *         nmsp_core_Dictionary* dict3 = nmsp_core_create_dictionary();<BR>
 *         <BR><BR>
 *         nmsp_core_dictionary_add(dict3, "KEY_C", "Hello", ASCII_STRING, 5);<BR>
 *         nmsp_core_dictionary_add(dict2, "KEY_B", dict3, DICTIONARY, sizeof(void*));<BR>
 *         nmsp_core_dictionary_add(dict1, "KEY_A", dict2, DICTIONARY, sizeof(void*));<BR>
 *         nmsp_core_delete_dictionary(dict1, <B>1</B>); // This recursively deletes dict1, dict2 and dict3.
 *
 **/
NMSP_CORE_EXPORT void nmsp_core_delete_dictionary(nmsp_core_Dictionary* dictionary, short recursive);

/**
 * \brief Determines if a dictionary data key exists.
 *
 * This function permits testing whether a key exists within a dictionary or not.
 * It allows the caller to differentiate between a key with a NULL value set and a missing key. 
 * It is recommended to call nmsp_core_dictionary_key_exists before you call nmsp_core_get_dictionary_value.
 *
 * \param key               Dictionary data key.
 *                          Must not be NULL.
 *
 * \param dictionary        Pointer to an nmsp_core_Dictionary.
 *                          Must not be NULL.
 *
 * \return      1 - Key exists.
 *              0 - Key does not exist.
 *
 * \see nmsp_core_Dictionary
 * \see nmsp_nmas_KeyValue
 * \see nmsp_nmas_Data
 * \see NMSP_CORE_CLASS_TYPE
**/
NMSP_CORE_EXPORT short nmsp_core_dictionary_key_exists(const char* key, const nmsp_core_Dictionary* dictionary);

/**
 * \brief Retrieves a dictionary data class.
 *
 * For the specified key, determines and returns the class type of that key.
 *
 * \param key               Dictionary data key.
 *                          Must not be NULL.
 *
 * \param dictionary        Pointer to an nmsp_core_Dictionary.
 *                          Must not be NULL.
 *
 * \return      NMSP_CORE_CLASS_TYPE of NMAS data.
 *              If an error occurs, INVALID_CLASS_TYPE is returned.
 *
 * \see nmsp_core_Dictionary
 * \see nmsp_nmas_KeyValue
 * \see nmsp_nmas_Data
 * \see NMSP_CORE_CLASS_TYPE
**/
NMSP_CORE_EXPORT NMSP_CORE_CLASS_TYPE nmsp_core_get_dictionary_class(const char* key,
                                                                     const nmsp_core_Dictionary* dictionary);

/**
 * \brief Retrieves a dictionary data value. 
 *
 * For a specified key, this function retrieves the corresponding data from the dictionary and
 * returns a pointer to it. This pointer should then be cast to the right data type, in 
 * order to properly access the data.
 *
 * \param key               Dictionary data key.
 *                          Must not be NULL.
 *
 * \param dictionary        Pointer to an nmsp_core_Dictionary.
 *                          Must not be NULL.
 *
 * \param length            Pointer to a long integer, in which the length in bytes of
 *                          the return data will be stored. Must be already pointing to
 *                          a pre-existing long integer.
 *                          Must not be NULL.
 *
 * \return      Pointer to NMAS data. This pointer should be cast to one of:
 *              char*, int, nmsp_core_Sequence*, or nmsp_core_Dictionary*.
 *              If an error occurs, NULL is returned.
 *              If the key does not exist, zero will be assigned to *length.
 *
 * \see nmsp_core_Dictionary
 * \see nmsp_nmas_KeyValue
 * \see nmsp_nmas_Data
 * \see NMSP_CORE_CLASS_TYPE
 **/
NMSP_CORE_EXPORT const void* nmsp_core_get_dictionary_value(const char*                 key,
                                                            const nmsp_core_Dictionary* dictionary,
                                                            unsigned long*              length);

/**
 * \brief Retrieves a dictionary string value.
 *
 * For a specified key, this function retrieves the corresponding string from the dictionary and
 * returns a pointer to it. If an error occurs, if the key does not exist or if the key is not a string type,
 * NULL is returned. 
 *
 * \param key               Dictionary key.
 *                          Must not be NULL.
 *
 * \param dictionary        Pointer to an nmsp_core_Dictionary.
 *                          Must not be NULL.
 *
 * \param length            Pointer to a long integer, in which the length in bytes of 
 *                          the return data will be stored. Must be already pointing to
 *                          a pre-existing long integer.
 *                          Must not be NULL.
 *
 * \return      Pointer to BYTE_STRING, ASCII_STRING or UTF8_STRING.
 *              If an error occurs, if the key does not exist or if the key is not a string type,
 *              NULL is returned.
 *
 * \see NMSP_CORE_CLASS_TYPE
 **/
NMSP_CORE_EXPORT const char* nmsp_core_get_dictionary_string_value(const char*                 key,
                                                                          const nmsp_core_Dictionary* dictionary,
                                                                          unsigned long*              length);

/**
 * \brief Retrieves a dictionary sequence value.
 *
 * For a specified key, this function retrieves the corresponding sequence from the dictionary and
 * returns a pointer to it. If an error occurs, if the key does not exist or if the key is not a sequence type,
 * NULL is returned. 
 *
 * \param key               Dictionary key.
 *                          Must not be NULL.
 *
 * \param dictionary        Pointer to an nmsp_core_Dictionary.
 *                          Must not be NULL.
 *
 * \return      Pointer to a nmsp_core_Sequence.
 *              If an error occurs, if the key does not exist or if the key is not a sequence type,
 *              NULL is returned.
 **/
NMSP_CORE_EXPORT const nmsp_core_Sequence* nmsp_core_get_dictionary_sequence_value(const char*                 key,
                                                                                          const nmsp_core_Dictionary* dictionary);

/**
 * \brief Retrieves a dictionary bool value.
 *
 * For a specified key, this function retrieves the corresponding bool from the dictionary and
 * returns its value. If an error occurs, if the key does not exist or if the key is not a bool type,
 * an invalid integer is returned. 
 *
 * \param key               Dictionary key.
 *                          Must not be NULL.
 *
 * \param dictionary        Pointer to an nmsp_core_Dictionary.
 *                          Must not be NULL.
 *
 * \return      An integer.
 *              If an error occurs, if the key does not exist or if the key is not an bool type,
 *              Invalid integer(0x7FFFFFFF) is returned.
 *
 **/
NMSP_CORE_EXPORT int nmsp_core_get_dictionary_bool_value(const char*                 key,
                                                         const nmsp_core_Dictionary* dictionary);

/**
 * \brief Retrieves a dictionary double value.
 *
 * For a specified key, this function retrieves the corresponding double from the dictionary and
 * returns its value. If an error occurs, if the key does not exist or if the key is not a double type,
 * an invalid double is returned. 
 *
 * \param key               Dictionary key.
 *                          Must not be NULL.
 *
 * \param dictionary        Pointer to an nmsp_core_Dictionary.
 *                          Must not be NULL.
 *
 * \return      An integer.
 *              If an error occurs, if the key does not exist or if the key is not an bool type,
 *              Invalid integer(0x7FFFFFFF) is returned.
 *
 **/
NMSP_CORE_EXPORT double nmsp_core_get_dictionary_double_value(const char*                 key,
                                                         const nmsp_core_Dictionary* dictionary);

/**
 * \brief Retrieves a dictionary integer value.
 *
 * For a specified key, this function retrieves the corresponding integer from the dictionary and
 * returns a pointer to it. If an error occurs, if the key does not exist or if the key is not an integer type,
 * an invalid integer is returned. 
 *
 * \param key               Dictionary key.
 *                          Must not be NULL.
 *
 * \param dictionary        Pointer to an nmsp_core_Dictionary.
 *                          Must not be NULL.
 *
 * \return      An integer.
 *              If an error occurs, if the key does not exist or if the key is not an integer type,
 *              Invalid integer(0x7FFFFFFF) is returned.
 *
 **/
NMSP_CORE_EXPORT int nmsp_core_get_dictionary_integer_value(const char*                 key,
                                                            const nmsp_core_Dictionary* dictionary);

/**
 * \brief Retrieves a dictionary dictionary value.
 *
 * For a specified key, this function retrieves the corresponding dictionary from the input dictionary and
 * returns a pointer to it. If an error occurs, if the key does not exist or if the key is not an dictionary 
 * type, NULL is returned. 
 *
 * \param key               Dictionary key.
 *                          Must not be NULL.
 *
 * \param dictionary        Pointer to an nmsp_core_Dictionary.
 *                          Must not be NULL.
 *
 * \return      Pointer to a nmsp_core_Dictionary.
 *              If an error occurs, if the key does not exist or if the key is not a dictionary type,
 *              NULL is returned.
 *
 **/
NMSP_CORE_EXPORT const nmsp_core_Dictionary* nmsp_core_get_dictionary_dictionary_value(const char*                 key,
                                                                                       const nmsp_core_Dictionary* dictionary);

/**
 * \brief Retrieves size of a dictionary object.
 *
 * \param dictionary        Pointer to an nmsp_core_Dictionary.
 *                          Must not be NULL.
 *
 * \return                  unsinged long of dictionary buffer size.
 *
**/
NMSP_CORE_EXPORT unsigned long nmsp_core_get_dictionary_buffer_size(nmsp_core_Dictionary* dictionary);

/**
 * \brief Retrieves content buffer of a dictionary object.
 *
 * \param dictionary        Pointer to an nmsp_core_Dictionary.
 *                          Must not be NULL.
 *
 * \param buffer            Pointer to dictionary buffer.
 *                          Must not be NULL.
 *
 * \return      1 - SUCCESS.
 *              0 - Failed.
 *
**/
NMSP_CORE_EXPORT short nmsp_core_get_dictionary_buffer(nmsp_core_Dictionary* dictionary, unsigned char* buffer);


/**
 * \brief Create a dictionary from  a dictionary buffer.
 *
 * \param buffer            Pointer to dictionary buffer.
 *                          Must not be NULL.
 *
 * \param length            unsigned long of buffer length.
 *                          Must not be NULL.
 *
 * \return      Pointer to a nmsp_core_Dictionary.
 *              If an error occurs, if the key does not exist or if the key is not a dictionary type,
 *              NULL is returned.
 *
**/
NMSP_CORE_EXPORT nmsp_core_Dictionary* nmsp_core_create_dictionary_from_buffer(const unsigned char* buffer, unsigned long length);


/**
 * \brief Creates an nmsp_core_Sequence object.
 *
 * Returns a pointer to a newly allocated nmsp_core_Sequence. If the allocation
 * fails, NULL will be returned.
 * To delete the nmsp_core_Sequence, the function nmsp_core_delete_sequence() must 
 * be used.
 *
 * \return      Pointer to an nmsp_core_Sequence. If an error occurs, NULL is returned.
 **/
NMSP_CORE_EXPORT nmsp_core_Sequence* nmsp_core_create_sequence(void);

/**
 * \brief Adds a value to an nmsp_core_Sequence.
 * This function adds a new element to the end of an existing sequence. I.e., if the sequence already
 * has 3 elements, the index of the added element will be 3.
 *        For all value types, a copy is made.
 *
 * \param sequence              Pointer to an nmsp_core_Sequence.
 *                              Must not be NULL.
 *
 * \param value                 Pointer to a value. Can be: char*, int*, nmsp_core_Sequence*,
 *                              or nmsp_core_Dictionary*, depending on clss (class type).
 *
 * \param clss                  nmsp_nmas_ClassTypes. This value must match whatever type is passed
 *                              in the value parameter.                           
 *
 * \param value_length          Length of value, in bytes. Mandatory for values of class type:
 *                              BYTE_STRING, ASCII_STRING, and UTF8_STRING.
 *                              Not mandatory for values of other class types.
 *
 * \return      NMSP_NMAS_OK if the value is inserted into the dictionary successfully.
 *              NMSP_NMAS_ERROR if an error occurs.
 *              NMSP_NMAS_OUT_OF_MEMORY if memory allocation fails.
 **/
NMSP_CORE_EXPORT NMSP_CORE_STATUS nmsp_core_sequence_add(nmsp_core_Sequence*  sequence,
                                                         const void*          value,
                                                         NMSP_CORE_CLASS_TYPE clss,
                                                         long                 value_length);

/**
 * \brief Retrieves the number of elements in a nmsp_core_Sequence.
 *
 * This function retutns the total number of elements stored within the specified sequence.
 *
 * \param sequence              Pointer to an nmsp_core_Sequence.
 *                              Must not be NULL.
 *
 * \return      Number of elements.
 **/
NMSP_CORE_EXPORT unsigned int nmsp_core_sequence_get_num_elements(nmsp_core_Sequence*  sequence);

/**
 * \brief Deletes an nmsp_core_Sequence.
 *
 * This function deletes a previously allocate nmsp_core_Sequence.
 * Like dictionaries, sequences can have deep structures
 * made up of embedded sequences that can contain other embedded sequences.
 * Using the recursive parameter, you can control which objects contained in the
 * sequence are deleted.
 *
 * \param sequence                   Pointer to an nmsp_core_Sequence.
 *                                   Must not be NULL. 
 *
 * \param recursive                  0 - Do not recursively delete any object in the sequence;<BR>
 *                                   1 - Recursively delete the objects of the sequence.
 * \see nmsp_core_delete_dictionary
 **/
NMSP_CORE_EXPORT void nmsp_core_delete_sequence(nmsp_core_Sequence* sequence, short recursive);

/**
 * \brief Retrieves a sequence data class.
 *
 * This function returns the class type of the data stored in the sequence
 * at the specified index. See NMSP_CORE_CLASS_TYPE for details about the
 * supported class types.
 *
 * \param index              Sequence data index.
 *
 * \param sequence           Pointer to an nmsp_core_Sequence.
 *                           Must not be NULL.
 *
 * \return      NMSP_CORE_CLASS_TYPE of NMAS data.
 *              If an error occurs, INVALID_CLASS_TYPE is returned.
 *
 * \see nmsp_core_Sequence
 * \see nmsp_nmas_Data
 * \see NMSP_CORE_CLASS_TYPE
**/
NMSP_CORE_EXPORT NMSP_CORE_CLASS_TYPE nmsp_core_get_sequence_class(const unsigned int        index,
                                                                            const nmsp_core_Sequence* sequence);
/**
 * \brief Retrieves sequence data. Deprecated, use nmsp_nmas_get_sequence_xxxx_value().
 *
 * For a specified index, this function retrieves the corresponding data from the sequence and
 * returns a pointer to it. This pointer should then be cast to the right data type, in 
 * order to properly access the data.
 *
 * \param index             Sequence data index.
 *
 * \param sequence          Pointer to an nmsp_core_Sequence.
 *                          Must not be NULL.
 *
 * \param length            Pointer to a long integer, in which the length in bytes of 
 *                          the return data will be stored. Must be already pointing to
 *                          a pre-existing long integer.
 *                          Must not be NULL.
 *
 * \return      Pointer to NMAS data. This pointer should be cast to one of:
 *              char*, int, nmsp_core_Sequence*, or nmsp_core_Dictionary*.
 *              If an error occurs or if the index is out of range, NULL is returned.
 *
 *  \see nmsp_core_Sequence
 *  \see nmsp_nmas_Data
 *  \see NMSP_CORE_CLASS_TYPE
 **/
NMSP_CORE_EXPORT const void* nmsp_core_get_sequence_value(const unsigned int        index,
                                                          const nmsp_core_Sequence* sequence,
                                                          unsigned long*            length);

/**
 * \brief Retrieves a sequence string element.
 *
 * For a specified index, this function retrieves the corresponding string from the sequence and
 * returns a pointer to it. If an error occurs, if the index is out of range or if data at the
 * index is not a string type, NULL is returned. 
 *
 * \param index             Sequence index.
 *
 * \param sequence          Pointer to an nmsp_core_Sequence.
 *                          Must not be NULL.
 *
 * \param length            Pointer to a long integer, in which the length in bytes of 
 *                          the return data will be stored. Must be already pointing to 
 *                          a pre-existing long integer.
 *                          Must not be NULL.
 *
 * \return      Pointer to BYTE_STRING, ASCII_STRING or UTF8_STRING.
 *              If an error occurs, if the index is out of range or if the element is of wrong type,
 *              NULL is returned.
 *
 *  \see NMSP_CORE_CLASS_TYPE
 **/
NMSP_CORE_EXPORT const char* nmsp_core_get_sequence_string_value(const unsigned int        index,
                                                                          const nmsp_core_Sequence* sequence,
                                                                          unsigned long*            length);

/**
 * \brief Retrieves a sequence sequence element.
 *
 * For a specified index, this function retrieves the corresponding sequence from the input 
 * sequence and returns a pointer to it. If an error occurs, if the index is out of range or
 * if data at the index is not a sequence type, NULL is returned. 
 *
 * \param index             Sequence index.
 *
 * \param sequence          Pointer to an nmsp_core_Sequence.
 *                          Must not be NULL.
 *
 * \return      Pointer to a nmsp_core_Sequence.
 *              If an error occurs, if the index is out of range or if the element is of wrong type,
 *              NULL is returned.
 **/
NMSP_CORE_EXPORT const nmsp_core_Sequence* nmsp_core_get_sequence_sequence_value(const unsigned int        index,
                                                                                          const nmsp_core_Sequence* sequence);

/**
 * \brief Retrieves a sequence integer element.
 *
 * For a specified index, this function retrieves the corresponding string from the sequence and
 * returns a pointer to it. If an error occurs, if the index is out of range or if data at the
 * index is not a string type, NULL is returned. 
 *
 * \param index             Sequence index.
 *
 * \param sequence          Pointer to an nmsp_core_Sequence.
 *                          Must not be NULL.
 *
 * \return      Pointer to an integer.
 *              If an error occurs, if the index is out of range or if the element is of wrong type,
 *              Invalid integer(0x7FFFFFFF) is returned.
 **/
NMSP_CORE_EXPORT int nmsp_core_get_sequence_integer_value(const unsigned int        index,
                                                          const nmsp_core_Sequence* sequence);

/**
 * \brief Retrieves a sequence dictionary element.
 *
 * For a specified index, this function retrieves the corresponding dicionary from the sequence and
 * returns a pointer to it. If an error occurs, if the index is out of range or if data at the
 * index is not a dictionary type, NULL is returned. 
 *
 * \param index             Sequence index.
 *
 * \param sequence          Pointer to an nmsp_core_Sequence.
 *                          Must not be NULL.
 *
 * \return      Pointer to an nmsp_core_Dictionary.
 *              If an error occurs, if the index is out of range or if the element is of wrong type,
 *              NULL is returned.
 **/
NMSP_CORE_EXPORT const nmsp_core_Dictionary* nmsp_core_get_sequence_dictionary_value(const unsigned int        index,
                                                                                     const nmsp_core_Sequence* sequence);


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* NMSP_CORE_PDX_H */
