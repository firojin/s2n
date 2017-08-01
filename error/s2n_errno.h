/*
 * Copyright 2014 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License").
 * You may not use this file except in compliance with the License.
 * A copy of the License is located at
 *
 *  http://aws.amazon.com/apache2.0
 *
 * or in the "license" file accompanying this file. This file is distributed
 * on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
 * express or implied. See the License for the specific language governing
 * permissions and limitations under the License.
 */

#pragma once

#include <s2n.h>

/**
 * To easily retrieve error types, we split error values into two parts.
 * The upper 6 bits describe the error type and the lower bits describe the value within the category.
 * [ Error Type Bits(31-26) ][ Value Bits(25-0) ]
 */
#define S2N_ERR_NUM_VALUE_BITS 26

/* Start value for each error type. */
#define S2N_ERR_T_OK_START S2N_ERR_T_OK << S2N_ERR_NUM_VALUE_BITS
#define S2N_ERR_T_IO_START S2N_ERR_T_IO << S2N_ERR_NUM_VALUE_BITS
#define S2N_ERR_T_CLOSED_START S2N_ERR_T_CLOSED << S2N_ERR_NUM_VALUE_BITS
#define S2N_ERR_T_BLOCKED_START S2N_ERR_T_BLOCKED << S2N_ERR_NUM_VALUE_BITS
#define S2N_ERR_T_ALERT_START S2N_ERR_T_ALERT << S2N_ERR_NUM_VALUE_BITS
#define S2N_ERR_T_PROTO_START S2N_ERR_T_PROTO << S2N_ERR_NUM_VALUE_BITS
#define S2N_ERR_T_INTERNAL_START S2N_ERR_T_INTERNAL << S2N_ERR_NUM_VALUE_BITS
#define S2N_ERR_T_USAGE_START S2N_ERR_T_USAGE << S2N_ERR_NUM_VALUE_BITS

typedef enum {
    /* S2N_ERR_T_OK */
    S2N_ERR_OK = S2N_ERR_T_OK_START,
    /* S2N_ERR_T_IO */
    S2N_ERR_IO = S2N_ERR_T_IO_START,
    /* S2N_ERR_T_CLOSED */
    S2N_ERR_CLOSED = S2N_ERR_T_CLOSED_START,
    /* S2N_ERR_T_BLOCKED */
    S2N_ERR_BLOCKED = S2N_ERR_T_BLOCKED_START,
    /* S2N_ERR_T_ALERT */
    S2N_ERR_ALERT = S2N_ERR_T_ALERT_START,
    /* S2N_ERR_T_PROTO */
    S2N_ERR_ENCRYPT = S2N_ERR_T_PROTO_START,
    S2N_ERR_DECRYPT,
    S2N_ERR_BAD_MESSAGE,
    S2N_ERR_KEY_INIT,
    S2N_ERR_DH_SERIALIZING,
    S2N_ERR_DH_SHARED_SECRET,
    S2N_ERR_DH_WRITING_PUBLIC_KEY,
    S2N_ERR_DH_FAILED_SIGNING,
    S2N_ERR_DH_COPYING_PARAMETERS,
    S2N_ERR_DH_GENERATING_PARAMETERS,
    S2N_ERR_CIPHER_NOT_SUPPORTED,
    S2N_ERR_NO_APPLICATION_PROTOCOL,
    S2N_ERR_FALLBACK_DETECTED,
    S2N_ERR_HASH_DIGEST_FAILED,
    S2N_ERR_HASH_INIT_FAILED,
    S2N_ERR_HASH_UPDATE_FAILED,
    S2N_ERR_DECODE_CERTIFICATE,
    S2N_ERR_DECODE_PRIVATE_KEY,
    S2N_ERR_INVALID_SIGNATURE_ALGORITHM,
    S2N_ERR_CBC_VERIFY,
    S2N_ERR_DH_COPYING_PUBLIC_KEY,
    S2N_ERR_SIGN,
    S2N_ERR_VERIFY_SIGNATURE,
    S2N_ERR_ECDHE_GEN_KEY,
    S2N_ERR_ECDHE_SHARED_SECRET,
    S2N_ERR_ECDHE_UNSUPPORTED_CURVE,
    S2N_ERR_ECDHE_SERIALIZING,
    S2N_ERR_SHUTDOWN_RECORD_TYPE,
    S2N_ERR_SHUTDOWN_CLOSED,
    S2N_ERR_NON_EMPTY_RENEGOTIATION_INFO,
    S2N_ERR_RECORD_LIMIT,
    S2N_ERR_CERT_UNTRUSTED,
    S2N_ERR_CERT_TYPE_UNSUPPORTED,
    /* S2N_ERR_T_INTERNAL */
    S2N_ERR_MADVISE = S2N_ERR_T_INTERNAL_START,
    S2N_ERR_ALLOC,
    S2N_ERR_MLOCK,
    S2N_ERR_MUNLOCK,
    S2N_ERR_FSTAT,
    S2N_ERR_OPEN,
    S2N_ERR_MMAP,
    S2N_ERR_NOMEM,
    S2N_ERR_NULL,
    S2N_ERR_SAFETY,
    S2N_ERR_NOT_INITIALIZED,
    S2N_ERR_RANDOM_UNINITIALIZED,
    S2N_ERR_OPEN_RANDOM,
    S2N_ERR_RESIZE_STATIC_STUFFER,
    S2N_ERR_RESIZE_TAINTED_STUFFER,
    S2N_ERR_STUFFER_OUT_OF_DATA,
    S2N_ERR_STUFFER_IS_FULL,
    S2N_ERR_HASH_INVALID_ALGORITHM,
    S2N_ERR_PRF_INVALID_ALGORITHM,
    S2N_ERR_P_HASH_INVALID_ALGORITHM,
    S2N_ERR_P_HASH_INIT_FAILED,
    S2N_ERR_P_HASH_UPDATE_FAILED,
    S2N_ERR_P_HASH_FINAL_FAILED,
    S2N_ERR_P_HASH_WIPE_FAILED,
    S2N_ERR_HMAC_INVALID_ALGORITHM,
    S2N_ERR_HKDF_OUTPUT_SIZE,
    S2N_ERR_ALERT_PRESENT,
    S2N_ERR_HANDSHAKE_STATE,
    S2N_ERR_SHUTDOWN_PAUSED,
    S2N_ERR_SIZE_MISMATCH,
    S2N_ERR_DRBG,
    S2N_ERR_DRBG_REQUEST_SIZE,
    S2N_ERR_PRIVATE_KEY_CHECK,
    S2N_ERR_CIPHER_TYPE,
    S2N_ERR_MAP_DUPLICATE,
    S2N_ERR_MAP_IMMUTABLE,
    S2N_ERR_MAP_MUTABLE,
    S2N_ERR_INITIAL_HMAC,
    S2N_ERR_INVALID_NONCE_TYPE,
    S2N_ERR_UNIMPLEMENTED,
    /* S2N_ERR_T_USAGE */
    S2N_ERR_NO_ALERT = S2N_ERR_T_USAGE_START,
    S2N_ERR_CLIENT_MODE,
    S2N_ERR_CLIENT_MODE_DISABLED,
    S2N_ERR_INVALID_BASE64,
    S2N_ERR_INVALID_PEM,
    S2N_ERR_DH_PARAMS_CREATE,
    S2N_ERR_DH_TOO_SMALL,
    S2N_ERR_DH_PARAMETER_CHECK,
    S2N_ERR_INVALID_PKCS3,
    S2N_ERR_NO_CERTIFICATE_IN_PEM,
    S2N_ERR_SERVER_NAME_TOO_LONG,
    S2N_ERR_INVALID_CIPHER_PREFERENCES,
    S2N_ERR_APPLICATION_PROTOCOL_TOO_LONG,
    S2N_ERR_KEY_MISMATCH,
    S2N_ERR_SEND_SIZE,
    S2N_ERR_CORK_SET_ON_UNMANAGED,
    S2N_ERR_UNRECOGNIZED_EXTENSION,
    S2N_ERR_INVALID_SCT_LIST,
    S2N_ERR_INVALID_OCSP_RESPONSE,
    S2N_ERR_CANCELLED,
} s2n_error;

#define S2N_DEBUG_STR_LEN 128
extern __thread const char *s2n_debug_str;

#define TO_STRING(s) #s
#define STRING_(s) TO_STRING(s)
#define STRING__LINE__ STRING_(__LINE__)

#define _S2N_DEBUG_LINE     "Error encountered in " __FILE__ " line " STRING__LINE__
#define _S2N_ERROR( x )     do { s2n_debug_str = _S2N_DEBUG_LINE; s2n_errno = ( x ); } while (0)
#define S2N_ERROR( x )      do { _S2N_ERROR( ( x ) ); return -1; } while (0)
#define S2N_ERROR_PTR( x )  do { _S2N_ERROR( ( x ) ); return NULL; } while (0)
