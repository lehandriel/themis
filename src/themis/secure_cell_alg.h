/*
 * Copyright (c) 2015 Cossack Labs Limited
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef THEMIS_SECURE_CELL_ALG_H
#define THEMIS_SECURE_CELL_ALG_H

#include <soter/soter_sym.h>

#ifndef THEMIS_DEFAULT_PBKDF2_ITERATIONS
#define THEMIS_DEFAULT_PBKDF2_ITERATIONS 314110
#endif

#ifdef THEMIS_AUTH_SYM_ALG_AES_256_GCM
#define THEMIS_AUTH_SYM_KEY_LENGTH SOTER_SYM_256_KEY_LENGTH
#define THEMIS_AUTH_SYM_ALG (SOTER_SYM_AES_GCM | THEMIS_AUTH_SYM_KEY_LENGTH)
#define THEMIS_AUTH_SYM_IV_LENGTH 12
#define THEMIS_AUTH_SYM_AUTH_TAG_LENGTH 16
#define THEMIS_AUTH_SYM_PASSPHRASE_ALG (THEMIS_AUTH_SYM_ALG | SOTER_SYM_PBKDF2)
#define THEMIS_AUTH_SYM_PBKDF2_SALT_LENGTH 16
#define THEMIS_AUTH_SYM_PBKDF2_ITERATIONS (THEMIS_DEFAULT_PBKDF2_ITERATIONS)
#endif

#ifdef THEMIS_AUTH_SYM_ALG_AES_128_GCM
#define THEMIS_AUTH_SYM_KEY_LENGTH SOTER_SYM_128_KEY_LENGTH
#define THEMIS_AUTH_SYM_ALG (SOTER_SYM_AES_GCM | THEMIS_AUTH_SYM_KEY_LENGTH)
#define THEMIS_AUTH_SYM_IV_LENGTH 12
#define THEMIS_AUTH_SYM_AUTH_TAG_LENGTH 16
#define THEMIS_AUTH_SYM_PASSPHRASE_ALG (THEMIS_AUTH_SYM_ALG | SOTER_SYM_PBKDF2)
#define THEMIS_AUTH_SYM_PBKDF2_SALT_LENGTH 16
#define THEMIS_AUTH_SYM_PBKDF2_ITERATIONS (THEMIS_DEFAULT_PBKDF2_ITERATIONS)
#endif

#ifdef THEMIS_AUTH_SYM_ALG_AES_192_GCM
#define THEMIS_AUTH_SYM_KEY_LENGTH SOTER_SYM_192_KEY_LENGTH
#define THEMIS_AUTH_SYM_ALG (SOTER_SYM_AES_GCM | THEMIS_AUTH_SYM_KEY_LENGTH)
#define THEMIS_AUTH_SYM_IV_LENGTH 12
#define THEMIS_AUTH_SYM_AUTH_TAG_LENGTH 16
#define THEMIS_AUTH_SYM_PASSPHRASE_ALG (THEMIS_AUTH_SYM_ALG | SOTER_SYM_PBKDF2)
#define THEMIS_AUTH_SYM_PBKDF2_SALT_LENGTH 16
#define THEMIS_AUTH_SYM_PBKDF2_ITERATIONS (THEMIS_DEFAULT_PBKDF2_ITERATIONS)
#endif

/*default values*/
#ifndef THEMIS_AUTH_SYM_ALG
#define THEMIS_AUTH_SYM_KEY_LENGTH SOTER_SYM_256_KEY_LENGTH
#define THEMIS_AUTH_SYM_ALG (SOTER_SYM_AES_GCM | THEMIS_AUTH_SYM_KEY_LENGTH)
#define THEMIS_AUTH_SYM_IV_LENGTH 12
#define THEMIS_AUTH_SYM_AUTH_TAG_LENGTH 16
#define THEMIS_AUTH_SYM_PASSPHRASE_ALG (THEMIS_AUTH_SYM_ALG | SOTER_SYM_PBKDF2)
#define THEMIS_AUTH_SYM_PBKDF2_SALT_LENGTH 16
#define THEMIS_AUTH_SYM_PBKDF2_ITERATIONS (THEMIS_DEFAULT_PBKDF2_ITERATIONS)
#endif

#define THEMIS_AUTH_SYM_MAX_KEY_LENGTH SOTER_SYM_256_KEY_LENGTH

#ifdef THEMIS_SYM_ALG_AES_256_CTR
#define THEMIS_SYM_KEY_LENGTH SOTER_SYM_256_KEY_LENGTH
#define THEMIS_SYM_ALG (SOTER_SYM_AES_CTR | THEMIS_SYM_KEY_LENGTH)
#define THEMIS_SYM_IV_LENGTH 16
#endif

#ifdef THEMIS_SYM_ALG_AES_192_CTR
#define THEMIS_SYM_KEY_LENGTH SOTER_SYM_192_KEY_LENGTH
#define THEMIS_SYM_ALG (SOTER_SYM_AES_CTR | THEMIS_SYM_KEY_LENGTH)
#define THEMIS_SYM_IV_LENGTH 16
#endif

#ifdef THEMIS_SYM_ALG_AES_128_CTR
#define THEMIS_SYM_KEY_LENGTH SOTER_SYM_128_KEY_LENGTH
#define THEMIS_SYM_ALG (SOTER_SYM_AES_CTR | THEMIS_SYM_KEY_LENGTH)
#define THEMIS_SYM_IV_LENGTH 16
#endif

/*default values*/
#ifndef THEMIS_SYM_ALG

#define THEMIS_SYM_KEY_LENGTH SOTER_SYM_256_KEY_LENGTH
#define THEMIS_SYM_ALG (SOTER_SYM_AES_CTR | THEMIS_SYM_KEY_LENGTH)
#define THEMIS_SYM_IV_LENGTH 16
#endif

static inline bool soter_alg_reserved_bits_valid(uint32_t alg)
{
    static const uint32_t used_bits = SOTER_SYM_KEY_LENGTH_MASK | SOTER_SYM_PADDING_MASK
                                      | SOTER_SYM_KDF_MASK | SOTER_SYM_ALG_MASK;
    return (alg & ~used_bits) == 0;
}

static inline size_t soter_alg_key_length(uint32_t alg)
{
    return (alg & SOTER_SYM_KEY_LENGTH_MASK) / 8;
}

static inline uint32_t soter_alg_kdf(uint32_t alg)
{
    return alg & SOTER_SYM_KDF_MASK;
}

#endif /* THEMIS_SECURE_CELL_ALG_H */
