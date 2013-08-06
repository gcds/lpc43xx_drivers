/*
 * @brief I2C registers and driver functions
 *
 * @note
 * Copyright(C) NXP Semiconductors, 2012
 * All rights reserved.
 *
 * @par
 * Software that is described herein is for illustrative purposes only
 * which provides customers with programming information regarding the
 * LPC products.  This software is supplied "AS IS" without any warranties of
 * any kind, and NXP Semiconductors and its licensor disclaim any and
 * all warranties, express or implied, including all implied warranties of
 * merchantability, fitness for a particular purpose and non-infringement of
 * intellectual property rights.  NXP Semiconductors assumes no responsibility
 * or liability for the use of the software, conveys no license or rights under any
 * patent, copyright, mask work right, or any other intellectual property rights in
 * or to any products. NXP Semiconductors reserves the right to make changes
 * in the software without notification. NXP Semiconductors also makes no
 * representation or warranty that such application will be suitable for the
 * specified use without further testing or modification.
 *
 * @par
 * Permission to use, copy, modify, and distribute this software and its
 * documentation is hereby granted, under NXP Semiconductors' and its
 * licensor's relevant copyrights in the software, without fee, provided that it
 * is used in conjunction with NXP Semiconductors microcontrollers.  This
 * copyright, permission, and disclaimer notice must appear in all copies of
 * this code.
 */

#ifndef __I2C_001_H_
#define __I2C_001_H_

#include "sys_config.h"
#include "cmsis.h"

#ifdef __cplusplus
extern "C" {
#endif

/** @defgroup IP_I2C_001 IP: I2C register block and driver
 * @ingroup IP_Drivers
 * @{
 */

/**
 * @brief I2C register block structure
 */
typedef struct {				/*!< I2C0 Structure         */
	__IO uint32_t CONSET;		/*!< I2C Control Set Register. When a one is written to a bit of this register, the corresponding bit in the I2C control register is set. Writing a zero has no effect on the corresponding bit in the I2C control register. */
	__I  uint32_t STAT;			/*!< I2C Status Register. During I2C operation, this register provides detailed status codes that allow software to determine the next action needed. */
	__IO uint32_t DAT;			/*!< I2C Data Register. During master or slave transmit mode, data to be transmitted is written to this register. During master or slave receive mode, data that has been received may be read from this register. */
	__IO uint32_t ADR0;			/*!< I2C Slave Address Register 0. Contains the 7-bit slave address for operation of the I2C interface in slave mode, and is not used in master mode. The least significant bit determines whether a slave responds to the General Call address. */
	__IO uint32_t SCLH;			/*!< SCH Duty Cycle Register High Half Word. Determines the high time of the I2C clock. */
	__IO uint32_t SCLL;			/*!< SCL Duty Cycle Register Low Half Word. Determines the low time of the I2C clock. SCLL and SCLH together determine the clock frequency generated by an I2C master and certain times used in slave mode. */
	__O  uint32_t CONCLR;		/*!< I2C Control Clear Register. When a one is written to a bit of this register, the corresponding bit in the I2C control register is cleared. Writing a zero has no effect on the corresponding bit in the I2C control register. */
	__IO uint32_t MMCTRL;		/*!< Monitor mode control register. */
	__IO uint32_t ADR1;			/*!< I2C Slave Address Register. Contains the 7-bit slave address for operation of the I2C interface in slave mode, and is not used in master mode. The least significant bit determines whether a slave responds to the General Call address. */
	__IO uint32_t ADR2;			/*!< I2C Slave Address Register. Contains the 7-bit slave address for operation of the I2C interface in slave mode, and is not used in master mode. The least significant bit determines whether a slave responds to the General Call address. */
	__IO uint32_t ADR3;			/*!< I2C Slave Address Register. Contains the 7-bit slave address for operation of the I2C interface in slave mode, and is not used in master mode. The least significant bit determines whether a slave responds to the General Call address. */
	__I  uint32_t DATA_BUFFER;	/*!< Data buffer register. The contents of the 8 MSBs of the DAT shift register will be transferred to the DATA_BUFFER automatically after every nine bits (8 bits of data plus ACK or NACK) has been received on the bus. */
	__IO uint32_t MASK[4];		/*!< I2C Slave address mask register */
} IP_I2C_001_T;

/**
 * @brief I2C state handle return values
 */
#define I2C_STA_STO_RECV            0x20

/**
 * @brief I2C Control Set register description
 */
#define I2C_I2CONSET_AA             ((0x04))/*!< Assert acknowledge flag */
#define I2C_I2CONSET_SI             ((0x08))/*!< I2C interrupt flag */
#define I2C_I2CONSET_STO            ((0x10))/*!< STOP flag */
#define I2C_I2CONSET_STA            ((0x20))/*!< START flag */
#define I2C_I2CONSET_I2EN           ((0x40))/*!< I2C interface enable */

/**
 * @brief I2C Control Clear register description
 */
#define I2C_I2CONCLR_AAC            ((1 << 2))	/*!< Assert acknowledge Clear bit */
#define I2C_I2CONCLR_SIC            ((1 << 3))	/*!< I2C interrupt Clear bit */
#define I2C_I2CONCLR_STOC           ((1 << 4))	/*!< I2C STOP Clear bit */
#define I2C_I2CONCLR_STAC           ((1 << 5))	/*!< START flag Clear bit */
#define I2C_I2CONCLR_I2ENC          ((1 << 6))	/*!< I2C interface Disable bit */

/**
 * @brief I2C Status Code definition (I2C Status register)
 */
#define I2C_STAT_CODE_BITMASK       ((0xF8))/*!< Return Code mask in I2C status register */
#define I2C_STAT_CODE_ERROR         ((0xFF))/*!< Return Code error mask in I2C status register */

/**
 * @brief I2C return status code definitions
 */
#define I2C_I2STAT_NO_INF                       ((0xF8))/*!< No relevant information */
#define I2C_I2STAT_BUS_ERROR                    ((0x00))/*!< Bus Error */

/**
 * @brief I2C Master transmit mode
 */
#define I2C_I2STAT_M_TX_START                   ((0x08))/*!< A start condition has been transmitted */
#define I2C_I2STAT_M_TX_RESTART                 ((0x10))/*!< A repeat start condition has been transmitted */
#define I2C_I2STAT_M_TX_SLAW_ACK                ((0x18))/*!< SLA+W has been transmitted, ACK has been received */
#define I2C_I2STAT_M_TX_SLAW_NACK               ((0x20))/*!< SLA+W has been transmitted, NACK has been received */
#define I2C_I2STAT_M_TX_DAT_ACK                 ((0x28))/*!< Data has been transmitted, ACK has been received */
#define I2C_I2STAT_M_TX_DAT_NACK                ((0x30))/*!< Data has been transmitted, NACK has been received */
#define I2C_I2STAT_M_TX_ARB_LOST                ((0x38))/*!< Arbitration lost in SLA+R/W or Data bytes */

/**
 * @brief I2C Master receive mode
 */
#define I2C_I2STAT_M_RX_START                   ((0x08))/*!< A start condition has been transmitted */
#define I2C_I2STAT_M_RX_RESTART                 ((0x10))/*!< A repeat start condition has been transmitted */
#define I2C_I2STAT_M_RX_ARB_LOST                ((0x38))/*!< Arbitration lost */
#define I2C_I2STAT_M_RX_SLAR_ACK                ((0x40))/*!< SLA+R has been transmitted, ACK has been received */
#define I2C_I2STAT_M_RX_SLAR_NACK               ((0x48))/*!< SLA+R has been transmitted, NACK has been received */
#define I2C_I2STAT_M_RX_DAT_ACK                 ((0x50))/*!< Data has been received, ACK has been returned */
#define I2C_I2STAT_M_RX_DAT_NACK                ((0x58))/*!< Data has been received, NACK has been returned */

/**
 * @brief I2C Slave receive mode
 */
#define I2C_I2STAT_S_RX_SLAW_ACK                ((0x60))/*!< Own slave address has been received, ACK has been returned */
#define I2C_I2STAT_S_RX_ARB_LOST_M_SLA          ((0x68))/*!< Arbitration lost in SLA+R/W as master */
// #define I2C_I2STAT_S_RX_SLAW_ACK				((0x68)) /*!< Own SLA+W has been received, ACK returned */
#define I2C_I2STAT_S_RX_GENCALL_ACK             ((0x70))/*!< General call address has been received, ACK has been returned */
#define I2C_I2STAT_S_RX_ARB_LOST_M_GENCALL      ((0x78))/*!< Arbitration lost in SLA+R/W (GENERAL CALL) as master */
// #define I2C_I2STAT_S_RX_GENCALL_ACK				((0x78)) /*!< General call address has been received, ACK has been returned */
#define I2C_I2STAT_S_RX_PRE_SLA_DAT_ACK         ((0x80))/*!< Previously addressed with own SLA; Data has been received, ACK has been returned */
#define I2C_I2STAT_S_RX_PRE_SLA_DAT_NACK        ((0x88))/*!< Previously addressed with own SLA;Data has been received and NOT ACK has been returned */
#define I2C_I2STAT_S_RX_PRE_GENCALL_DAT_ACK     ((0x90))/*!< Previously addressed with General Call; Data has been received and ACK has been returned */
#define I2C_I2STAT_S_RX_PRE_GENCALL_DAT_NACK    ((0x98))/*!< Previously addressed with General Call; Data has been received and NOT ACK has been returned */
#define I2C_I2STAT_S_RX_STA_STO_SLVREC_SLVTRX   ((0xA0))/*!< A STOP condition or repeated START condition has been received while still addressed as SLV/REC (Slave Receive) or
														   SLV/TRX (Slave Transmit) */

/**
 * @brief I2C Slave transmit mode
 */
#define I2C_I2STAT_S_TX_SLAR_ACK                ((0xA8))/*!< Own SLA+R has been received, ACK has been returned */
#define I2C_I2STAT_S_TX_ARB_LOST_M_SLA          ((0xB0))/*!< Arbitration lost in SLA+R/W as master */
// #define I2C_I2STAT_S_TX_SLAR_ACK				((0xB0)) /*!< Own SLA+R has been received, ACK has been returned */
#define I2C_I2STAT_S_TX_DAT_ACK                 ((0xB8))/*!< Data has been transmitted, ACK has been received */
#define I2C_I2STAT_S_TX_DAT_NACK                ((0xC0))/*!< Data has been transmitted, NACK has been received */
#define I2C_I2STAT_S_TX_LAST_DAT_ACK            ((0xC8))/*!< Last data byte in I2DAT has been transmitted (AA = 0); ACK has been received */
#define I2C_SLAVE_TIME_OUT                      0x10000000UL/*!< Time out in case of using I2C slave mode */

/**
 * @brief I2C Data register definition
 */
#define I2C_I2DAT_BITMASK           ((0xFF))/*!< Mask for I2DAT register */
#define I2C_I2DAT_IDLE_CHAR         (0xFF)	/*!< Idle data value will be send out in slave mode in case of the actual expecting data requested from the master is greater than
											     its sending data length that can be supported */

/**
 * @brief I2C Monitor mode control register description
 */
#define I2C_I2MMCTRL_MM_ENA         ((1 << 0))			/**< Monitor mode enable */
#define I2C_I2MMCTRL_ENA_SCL        ((1 << 1))			/**< SCL output enable */
#define I2C_I2MMCTRL_MATCH_ALL      ((1 << 2))			/**< Select interrupt register match */
#define I2C_I2MMCTRL_BITMASK        ((0x07))		/**< Mask for I2MMCTRL register */

/**
 * @brief I2C Data buffer register description
 */
#define I2DATA_BUFFER_BITMASK       ((0xFF))/*!< I2C Data buffer register bit mask */

/**
 * @brief I2C Slave Address registers definition
 */
#define I2C_I2ADR_GC                ((1 << 0))	/*!< General Call enable bit */
#define I2C_I2ADR_BITMASK           ((0xFF))/*!< I2C Slave Address registers bit mask */

/**
 * @brief I2C Mask Register definition
 */
#define I2C_I2MASK_MASK(n)          ((n & 0xFE))/*!< I2C Mask Register mask field */

/**
 * @brief I2C SCL HIGH duty cycle Register definition
 */
#define I2C_I2SCLH_BITMASK          ((0xFFFF))	/*!< I2C SCL HIGH duty cycle Register bit mask */

/**
 * @brief I2C SCL LOW duty cycle Register definition
 */
#define I2C_I2SCLL_BITMASK          ((0xFFFF))	/*!< I2C SCL LOW duty cycle Register bit mask */

/**
 * @brief I2C status values
 */
#define I2C_SETUP_STATUS_ARBF   (1 << 8)	/**< Arbitration false */
#define I2C_SETUP_STATUS_NOACKF (1 << 9)	/**< No ACK returned */
#define I2C_SETUP_STATUS_DONE   (1 << 10)	/**< Status DONE */

/**
 * @brief I2C state handle return values
 */
#define I2C_OK                      0x00
#define I2C_BYTE_SENT               0x01
#define I2C_BYTE_RECV               0x02
#define I2C_LAST_BYTE_RECV          0x04
#define I2C_SEND_END                0x08
#define I2C_RECV_END                0x10
#define I2C_STA_STO_RECV            0x20

#define I2C_ERR                     (0x10000000)
#define I2C_NAK_RECV                (0x10000000 | 0x01)

#define I2C_CheckError(ErrorCode)   (ErrorCode & 0x10000000)

/**
 * @brief I2C monitor control configuration defines
 */
#define I2C_MONITOR_CFG_SCL_OUTPUT  I2C_I2MMCTRL_ENA_SCL		/**< SCL output enable */
#define I2C_MONITOR_CFG_MATCHALL    I2C_I2MMCTRL_MATCH_ALL		/**< Select interrupt register match */

/**
 * @brief Master transfer setup data structure definitions
 */
typedef struct {
	uint32_t          sl_addr7bit;			/**< Slave address in 7bit mode */
	uint8_t           *tx_data;				/**< Pointer to Transmit data - NULL if data transmit is not used */
	uint32_t          tx_length;			/**< Transmit data length - 0 if data transmit is not used*/
	uint32_t          tx_count;				/**< Current Transmit data counter */
	uint8_t           *rx_data;				/**< Pointer to Receive data - NULL if data receive is not used */
	uint32_t          rx_length;			/**< Receive data length - 0 if data receive is not used */
	uint32_t          rx_count;				/**< Current Receive data counter */
	uint32_t          retransmissions_max;	/**< Max Re-Transmission value */
	uint32_t          retransmissions_count;/**< Current Re-Transmission counter */
	uint32_t          status;				/**< Current status of I2C activity */
} I2C_M_SETUP_T;

/**
 * @brief Slave transfer setup data structure definitions
 */
typedef struct {
	uint8_t           *tx_data;		/**< Pointer to transmit data - NULL if data transmit is not used */
	uint32_t          tx_length;	/**< Transmit data length - 0 if data transmit is not used */
	uint32_t          tx_count;		/**< Current transmit data counter	*/
	uint8_t           *rx_data;		/**< Pointer to receive data - NULL if data received is not used */
	uint32_t          rx_length;	/**< Receive data length - 0 if data receive is not used */
	uint32_t          rx_count;		/**< Current receive data counter */
	uint32_t          status;		/**< Current status of I2C activity */
} I2C_S_SETUP_T;

/**
 * @brief Transfer option type definitions
 */
typedef enum IP_I2C_TRANSFER_OPT {
	I2C_TRANSFER_POLLING = 0,	/**< Transfer in polling mode */
	I2C_TRANSFER_INTERRUPT		/**< Transfer in interrupt mode */
} IP_I2C_TRANSFER_OPT_T;

/**
 * @brief I2C Own slave address setting structure
 */
typedef struct {
	uint8_t SlaveAddrChannel;	/**< Slave Address channel in I2C control, should be in range from 0..3 */
	uint8_t SlaveAddr_7bit;		/**< Value of 7-bit slave address */
	uint8_t GeneralCallState;	/**< Enable/Disable General Call Functionality when I2C control being in Slave mode, should be:
								   - ENABLE: Enable General Call function.
								   - DISABLE: Disable General Call function. */
	uint8_t SlaveAddrMaskValue;	/**< Any bit in this 8-bit value (bit 7:1) which is set to '1' will cause an automatic compare on
								   the corresponding bit of the received address when it is compared to the SlaveAddr_7bit value associated with this
								   mask register. In other words, bits in SlaveAddr_7bit value which are masked are not taken into account in determining
								   an address match */
} I2C_OWNSLAVEADDR_CFG_T;

typedef enum IP_I2C_MODE {
	I2C_MASTER_MODE,
	I2C_SLAVE_MODE,
	I2C_GENERAL_MODE,
} IP_I2C_MODE_T;

typedef enum IP_I2C_ID {
	I2C0 = 0,
#if defined(CHIP_LPC175X_6X) || defined(CHIP_LPC177X_8X) || defined(CHIP_LPC407X_8X) || defined(CHIP_LPC18XX) || \
	defined(CHIP_LPC43XX)
	I2C1,
#if defined(CHIP_LPC175X_6X) || defined(CHIP_LPC177X_8X) || defined(CHIP_LPC407X_8X)
	I2C2,
#endif
#endif
} IP_I2C_ID_T;

/**
 * @brief	Initializes the pI2C peripheral.
 * @param	pI2C	: Pointer to selected I2Cx peripheral
 * @return	Nothing
 */
void IP_I2C_Init(IP_I2C_001_T *pI2C);

/**
 * @brief	De-initializes the I2C peripheral registers to their default reset values.
 * @param	pI2C	: Pointer to selected I2Cx peripheral
 * @return	Nothing
 */
void IP_I2C_DeInit(IP_I2C_001_T *pI2C);

/**
 * @brief	Set up clock rate for I2Cx.
 * @param	pI2C		: Pointer to selected I2Cx peripheral
 * @param	SCLValue	: Value of I2CSCL register
 * @return	Nothing
 */
void IP_I2C_SetClockRate(IP_I2C_001_T *pI2C, uint32_t SCLValue);

/**
 * @brief	Enable I2C operation for master mode
 * @param	pI2C	: Pointer to selected I2C peripheral
 * @return	Nothing
 */
STATIC INLINE void IP_I2C_Master_Enable(IP_I2C_001_T *pI2C)
{
	pI2C->CONSET = I2C_I2CONSET_I2EN;
}

/**
 * @brief	Enable I2C operation for slave mode
 * @param	pI2C	: Pointer to selected I2C peripheral
 * @return	Nothing
 */
STATIC INLINE void IP_I2C_Slave_Enable(IP_I2C_001_T *pI2C)
{
	pI2C->CONSET = I2C_I2CONSET_I2EN | I2C_I2CONSET_AA;
}

/**
 * @brief	Disable I2C peripheral's operation
 * @param	pI2C	: Pointer to selected I2C peripheral
 * @return	Nothing
 */
STATIC INLINE void IP_I2C_Disable(IP_I2C_001_T *pI2C)
{
	pI2C->CONCLR = I2C_I2CONCLR_I2ENC;
}

/**
 * @brief	General Master Interrupt handler for I2C peripheral
 * @param	pI2C		: Pointer to selected I2Cx peripheral
 * @param	I2C_Num		: I2C port number, should be I2C0, I2C1 or I2C2
 * @return	Nothing
 */
void IP_I2C_Interrupt_MasterHandler(IP_I2C_001_T *pI2C, IP_I2C_ID_T I2C_Num);

/**
 * @brief	General Slave Interrupt handler for I2C peripheral
 * @param	pI2C		: Pointer to selected I2Cx peripheral
 * @param	I2C_Num		: I2C port number, should be I2C0, I2C1 or I2C2
 * @return	Nothing
 */
void IP_I2C_Interrupt_SlaveHandler (IP_I2C_001_T *pI2C, IP_I2C_ID_T I2C_Num);

/**
 * @brief	Transmit and Receive data in master mode
 * @param	pI2C		: Pointer to selected I2Cx peripheral
 * @param	I2C_Num		: I2C port number, should be I2C0, I2C1 or I2C2
 * @param	TransferCfg	: Pointer to a I2C_M_SETUP_T structure that contains specified
 *                        information about the configuration for master transfer.
 * @param	Opt			: a IP_I2C_TRANSFER_OPT_T type that selected for interrupt or polling mode.
 * @return	SUCCESS or ERROR
 * @note
 * - In case of using I2C to transmit/receive data only, either transmit/receive length set to 0
 * or transmit/receive data pointer set to NULL.
 * - In case of using I2C to transmit followed by receive data, transmit length, transmit data
 * pointer, receive length and receive data pointer should be set corresponding.
 */
Status IP_I2C_MasterTransferData(IP_I2C_001_T *pI2C,
								 IP_I2C_ID_T I2C_Num,
								 I2C_M_SETUP_T *TransferCfg,
								 IP_I2C_TRANSFER_OPT_T Opt);

/**
 * @brief	Receive and Transmit data in slave mode
 * @param	pI2C		: Pointer to selected I2Cx peripheral
 * @param	I2C_Num		: I2C port number, should be I2C0, I2C1 or I2C2
 * @param	TransferCfg	: Pointer to a I2C_S_SETUP_T structure that contains specified information
 *                        about the	configuration for master transfer.
 * @param	Opt			: IP_I2C_TRANSFER_OPT_T type that selected for interrupt or polling mode.
 * @return	SUCCESS or ERROR
 * @note
 * The mode of slave's operation depends on the command sent from master on the I2C bus. If the master
 * send a SLA+W command, this sub-routine will use receive data length and receive data pointer. If the
 * master send a SLA+R command, this sub-routine will use transmit data length and transmit data pointer.
 * If the master issue an repeat start command or a stop command, the slave will enable an time out condition,
 * during time out condition, if there's no activity on I2C bus, the slave will exit, otherwise (i.e. the master
 * send a SLA+R/W), the slave then switch to relevant operation mode. The time out should be used because the
 * return status code can not show difference from stop and repeat start command in slave operation.
 * In case of the expected data length from master is greater than data length that slave can support:
 * - In case of reading operation (from master): slave will return I2C_I2DAT_IDLE_CHAR value.
 * - In case of writing operation (from master): slave will ignore remain data from master.
 */
Status IP_I2C_SlaveTransferData(IP_I2C_001_T *pI2C,
								IP_I2C_ID_T I2C_Num,
								I2C_S_SETUP_T *TransferCfg,
								IP_I2C_TRANSFER_OPT_T Opt);

/**
 * @brief	Get status of Master Transfer
 * @param	I2C_Num	: I2C port number, should be I2C0, I2C1 or I2C2
 * @return	Master transfer status, could be TRUE (completed) or FALSE (not completed yet)
 */
bool    IP_I2C_Interrupt_MasterTransferComplete(IP_I2C_ID_T I2C_Num);

/**
 * @brief	Get status of Slave Transfer
 * @param	I2C_Num	: I2C port number, should be I2C0, I2C1 or I2C2
 * @return	Slave transfer status, could be TRUE (completed) or FALSE (not completed yet)
 */
bool    IP_I2C_Interrupt_SlaveTransferComplete(IP_I2C_ID_T I2C_Num);

/**
 * @brief	Set Own slave address in I2C peripheral corresponding to parameter specified in OwnSlaveAddrConfigStruct.
 * @param	pI2C						: I2C peripheral selected
 * @param	OwnSlaveAddrConfigStruct	: Pointer to a I2C_OWNSLAVEADDR_CFG_T structure that contains the
 *                      configuration information for the specified I2C slave address.
 * @return	Nothing
 */
void IP_I2C_SetOwnSlaveAddr(IP_I2C_001_T *pI2C, I2C_OWNSLAVEADDR_CFG_T *OwnSlaveAddrConfigStruct);

/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif /* __I2C_001_H_ */