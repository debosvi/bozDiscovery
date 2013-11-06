/**
 * \defgroup BOZ_DISCOVERY Discovery
 * @{
 */

#ifndef _BOZ_DISCOVERY_H_
#define _BOZ_DISCOVERY_H_

/*!
 * Discovery manager 
 * 
 * \note variable must be initialised to BOZ_DISC_ZERO.
 */
typedef struct boz_disc_s *boz_disc_t;

/*! 
 * Discovery manager init value 
 */
#define BOZ_DISC_ZERO NULL

/*!
 * \param[in,out] mgr
 * \return error code
 * \retval 0 on success
 * \retval -1 on failure (errno set accordingly)
 *
 * errno managed:
 * - 0 on success
 * - EINVAL if mgr is not set to BOZ_DISC_ZERO as input value
 * - EIO if mgr can't be instanciated
 */
int boz_discovery_init(boz_disc_t *mgr);

/*!
 * \param[in,out] mgr
 * \return error code
 * \retval 0 on success
 * \retval -1 on failure (errno set accordingly)
 *
 * errno managed:
 * - 0 on success
 * - EINVAL if mgr has not been set with \ref boz_discovery_init
 * 
 * \note \p mgr is reset to BOZ_DISC_ZERO on success
 */
int boz_discovery_term(boz_disc_t *mgr);

/*!
 * \param[in] mgr
 * \param[in] uri
 * \return register ID
 * \retval >=0 on success
 * \retval -1 on failure (errno set accordingly)
 *
 * errno managed:
 * - 0 on success
 * - EINVAL if mgr has not been set with \ref boz_discovery_init
 * - EFAULT if uri is NULL
 * - EFBIG if uri iexceeds max length managed
 * - EEXIST if uri is already registred to this manager
 * 
 */
int boz_discovery_register(const boz_disc_t mgr, const char* uri);

/*!
 * \param[in] mgr
 * \param[in] id
 * \return error code
 * \retval 0 on success
 * \retval -1 on failure (errno set accordingly)
 *
 * errno managed:
 * - 0 on success
 * - EINVAL if mgr has not been set with \ref boz_discovery_init
 * - ENOENT if id has not been registered before with \ref boz_discovery_register
 * 
 */
int boz_discovery_unregister(const boz_disc_t mgr, const int id);

/*!
 * \param[in] mgr
 * \param[in] id
 * \retval uri string
 * \retval NULL on failure (errno set accordingly)
 *
 * errno managed:
 * - 0 on success
 * - EINVAL if mgr has not been set with \ref boz_discovery_init
 * - ENOENT if ID has not been registered before with \ref boz_discovery_register
 * 
 * \note Returned uri string is a copy of the registered uri with \ref boz_discovery_register.
 * It must be freed by caller.
 */
char* boz_discovery_geturi(const boz_disc_t mgr, const int id);

#endif

/**
 * @}
 */
