#ifndef THRIFT_LINE_H
#define THRIFT_LINE_H

#include <iostream>
#include <map>
#include <optional>
#include <set>
#include <stack>
#include <stdexcept>
#include <cstdint>
#include <string>
#include <vector>
#include "Protocol/TCompactProtocol.h"

namespace protocol {

    enum class ApplicationType : uint32_t {
        ENUM_NONE = UINT32_MAX,
        IOS = 16,
        IOS_RC = 17,
        IOS_BETA = 18,
        IOS_ALPHA = 19,
        ANDROID = 32,
        ANDROID_RC = 33,
        ANDROID_BETA = 34,
        ANDROID_ALPHA = 35,
        WAP = 48,
        WAP_RC = 49,
        WAP_BETA = 50,
        WAP_ALPHA = 51,
        BOT = 64,
        BOT_RC = 65,
        BOT_BETA = 66,
        BOT_ALPHA = 67,
        WEB = 80,
        WEB_RC = 81,
        WEB_BETA = 82,
        WEB_ALPHA = 83,
        DESKTOPWIN = 96,
        DESKTOPWIN_RC = 97,
        DESKTOPWIN_BETA = 98,
        DESKTOPWIN_ALPHA = 99,
        DESKTOPMAC = 112,
        DESKTOPMAC_RC = 113,
        DESKTOPMAC_BETA = 114,
        DESKTOPMAC_ALPHA = 115,
        CHANNELGW = 128,
        CHANNELGW_RC = 129,
        CHANNELGW_BETA = 130,
        CHANNELGW_ALPHA = 131,
        CHANNELCP = 144,
        CHANNELCP_RC = 145,
        CHANNELCP_BETA = 146,
        CHANNELCP_ALPHA = 147,
        WINPHONE = 160,
        WINPHONE_RC = 161,
        WINPHONE_BETA = 162,
        WINPHONE_ALPHA = 163,
        BLACKBERRY = 176,
        BLACKBERRY_RC = 177,
        BLACKBERRY_BETA = 178,
        BLACKBERRY_ALPHA = 179,
        WINMETRO = 192,
        WINMETRO_RC = 193,
        WINMETRO_BETA = 194,
        WINMETRO_ALPHA = 195,
        S40 = 208,
        S40_RC = 209,
        S40_BETA = 210,
        S40_ALPHA = 211,
        CHRONO = 224,
        CHRONO_RC = 225,
        CHRONO_BETA = 226,
        CHRONO_ALPHA = 227,
        TIZEN = 256,
        TIZEN_RC = 257,
        TIZEN_BETA = 258,
        TIZEN_ALPHA = 259,
        VIRTUAL = 272,
        FIREFOXOS = 288,
        FIREFOXOS_RC = 289,
        FIREFOXOS_BETA = 290,
        FIREFOXOS_ALPHA = 291,
        IOSIPAD = 304,
        IOSIPAD_RC = 305,
        IOSIPAD_BETA = 306,
        IOSIPAD_ALPHA = 307,
        BIZIOS = 320,
        BIZIOS_RC = 321,
        BIZIOS_BETA = 322,
        BIZIOS_ALPHA = 323,
        BIZANDROID = 336,
        BIZANDROID_RC = 337,
        BIZANDROID_BETA = 338,
        BIZANDROID_ALPHA = 339,
        BIZBOT = 352,
        BIZBOT_RC = 353,
        BIZBOT_BETA = 354,
        BIZBOT_ALPHA = 355,
        CHROMEOS = 368,
        CHROMEOS_RC = 369,
        CHROMEOS_BETA = 370,
        CHROMEOS_ALPHA = 371,
        ANDROIDLITE = 384,
        ANDROIDLITE_RC = 385,
        ANDROIDLITE_BETA = 386,
        ANDROIDLITE_ALPHA = 387,
        WIN10 = 400,
        WIN10_RC = 401,
        WIN10_BETA = 402,
        WIN10_ALPHA = 403,
        BIZWEB = 416,
        BIZWEB_RC = 417,
        BIZWEB_BETA = 418,
        BIZWEB_ALPHA = 419,
        DUMMYPRIMARY = 432,
        DUMMYPRIMARY_RC = 433,
        DUMMYPRIMARY_BETA = 434,
        DUMMYPRIMARY_ALPHA = 435,
        SQUARE = 448,
        SQUARE_RC = 449,
        SQUARE_BETA = 450,
        SQUARE_ALPHA = 451,
        INTERNAL = 464,
        INTERNAL_RC = 465,
        INTERNAL_BETA = 466,
        INTERNAL_ALPHA = 467,
        CLOVAFRIENDS = 480,
        CLOVAFRIENDS_RC = 481,
        CLOVAFRIENDS_BETA = 482,
        CLOVAFRIENDS_ALPHA = 483
    };

    enum class ChannelPermission : uint32_t {
        ENUM_NONE = UINT32_MAX,
        PROFILE = 0,
        FRIENDS = 1,
        GROUP = 2
    };

    enum class AsymmetricKeyAlgorithm : uint32_t {
        ENUM_NONE = UINT32_MAX,
        ASYMMETRIC_KEY_ALGORITHM_RSA = 1,
        ASYMMETRIC_KEY_ALGORITHM_ECDH = 2
    };

    enum class BeaconNotificationType : uint32_t {
        ENUM_NONE = UINT32_MAX,
        BUTTON = 1,
        ENTRY_SELECTED = 2,
        BROADCAST_ENTER = 3,
        BROADCAST_LEAVE = 4
    };

    enum class BotType : uint32_t {
        ENUM_NONE = UINT32_MAX,
        RESERVED = 0,
        OFFICIAL = 1,
        LINE_AT_0 = 2,
        LINE_AT = 3
    };

    enum class BuddyBannerLinkType : uint32_t {
        ENUM_NONE = UINT32_MAX,
        BUDDY_BANNER_LINK_HIDDEN = 0,
        BUDDY_BANNER_LINK_MID = 1,
        BUDDY_BANNER_LINK_URL = 2
    };

    enum class BuddyCollectionType : uint32_t {
        ENUM_NONE = UINT32_MAX,
        NORMAL = 0,
        NEW = 1,
        ONAIR = 2,
        POPULAR = 3
    };

    enum class BuddyOnAirLabel : uint32_t {
        ENUM_NONE = UINT32_MAX,
        ON_AIR = 0,
        LIVE = 1
    };

    enum class BuddyOnAirType : uint32_t {
        ENUM_NONE = UINT32_MAX,
        NORMAL = 0,
        VIDEOCAM = 1,
        VOIP = 2,
        RECORD = 3
    };

    enum class BuddyProfilePopupType : uint32_t {
        ENUM_NONE = UINT32_MAX,
        NONE = 0,
        WEB = 1
    };

    enum class BuddyResultState : uint32_t {
        ENUM_NONE = UINT32_MAX,
        ACCEPTED = 1,
        SUCCEEDED = 2,
        FAILED = 3,
        CANCELLED = 4,
        NOTIFY_FAILED = 5,
        STORING = 11,
        UPLOADING = 21,
        NOTIFYING = 31,
        REMOVING_SUBSCRIPTION = 41,
        UNREGISTERING_ACCOUNT = 42,
        NOTIFYING_LEAVE_CHAT = 43
    };

    enum class BuddySearchRequestSource : uint32_t {
        ENUM_NONE = UINT32_MAX,
        NA = 0,
        FRIEND_VIEW = 1,
        OFFICIAL_ACCOUNT_VIEW = 2
    };

    enum class BuddyStatusBarDisplayType : uint32_t {
        ENUM_NONE = UINT32_MAX,
        NOT_A_FRIEND = 0,
        ALWAYS = 1
    };

    enum class CarrierCode : uint32_t {
        ENUM_NONE = UINT32_MAX,
        NOT_SPECIFIED = 0,
        JP_DOCOMO = 1,
        JP_AU = 2,
        JP_SOFTBANK = 3,
        KR_SKT = 17,
        KR_KT = 18,
        KR_LGT = 19,
        JP_DOCOMO_LINE = 4
    };

    enum class ChannelConfiguration : uint32_t {
        ENUM_NONE = UINT32_MAX,
        MESSAGE = 0,
        MESSAGE_NOTIFICATION = 1,
        NOTIFICATION_CENTER = 2
    };

    enum class ChannelErrorCode : uint32_t {
        ENUM_NONE = UINT32_MAX,
        ILLEGAL_ARGUMENT = 0,
        INTERNAL_ERROR = 1,
        CONNECTION_ERROR = 2,
        AUTHENTICATIONI_FAILED = 3,
        NEED_PERMISSION_APPROVAL = 4,
        COIN_NOT_USABLE = 5,
        WEBVIEW_NOT_ALLOWED = 6
    };

    enum class ChannelSyncTarget : uint32_t {
        ENUM_NONE = UINT32_MAX,
        ALL = 255,
        CHANNEL_INFO = 1,
        CHANNEL_TOKEN = 2,
        COMMON_DOMAIN = 4
    };

    enum class ChannelSyncType : uint32_t {
        ENUM_NONE = UINT32_MAX,
        SYNC = 0,
        REMOVE = 1,
        REMOVE_ALL = 2
    };

    enum class CommitMessageResultCode : uint32_t {
        ENUM_NONE = UINT32_MAX,
        DELIVERED = 0,
        DELIVERY_SKIPPED = 1,
        DELIVERY_RESTRICTED = 2
    };

    enum class ContactAttribute : uint32_t {
        ENUM_NONE = UINT32_MAX,
        CONTACT_ATTRIBUTE_CAPABLE_VOICE_CALL = 1,
        CONTACT_ATTRIBUTE_CAPABLE_VIDEO_CALL = 2,
        CONTACT_ATTRIBUTE_CAPABLE_MY_HOME = 16,
        CONTACT_ATTRIBUTE_CAPABLE_BUDDY = 32
    };

    enum class ContactCategory : uint32_t {
        ENUM_NONE = UINT32_MAX,
        NORMAL = 0,
        RECOMMEND = 1,
        BLOCKED = 2
    };

    enum class ContactRelation : uint32_t {
        ENUM_NONE = UINT32_MAX,
        ONEWAY = 0,
        BOTH = 1,
        NOT_REGISTERED = 2
    };

    enum class ContactSetting : uint32_t {
        ENUM_NONE = UINT32_MAX,
        CONTACT_SETTING_NOTIFICATION_DISABLE = 1,
        CONTACT_SETTING_DISPLAY_NAME_OVERRIDE = 2,
        CONTACT_SETTING_CONTACT_HIDE = 4,
        CONTACT_SETTING_FAVORITE = 8,
        CONTACT_SETTING_DELETE = 16
    };

    enum class ContactStatus : uint32_t {
        ENUM_NONE = UINT32_MAX,
        UNSPECIFIED = 0,
        FRIEND = 1,
        FRIEND_BLOCKED = 2,
        RECOMMEND = 3,
        RECOMMEND_BLOCKED = 4,
        DELETED = 5,
        DELETED_BLOCKED = 6
    };

    enum class ContactType : uint32_t {
        ENUM_NONE = UINT32_MAX,
        MID = 0,
        PHONE = 1,
        EMAIL = 2,
        USERID = 3,
        PROXIMITY = 4,
        GROUP = 5,
        USER = 6,
        QRCODE = 7,
        PROMOTION_BOT = 8,
        CONTACT_MESSAGE = 9,
        FRIEND_REQUEST = 10,
        REPAIR = 128,
        FACEBOOK = 2305,
        SINA = 2306,
        RENREN = 2307,
        FEIXIN = 2308,
        BBM = 2309,
        BEACON = 11
    };

    enum class ContentType : uint32_t {
        ENUM_NONE = UINT32_MAX,
        NONE = 0,
        IMAGE = 1,
        VIDEO = 2,
        AUDIO = 3,
        HTML = 4,
        PDF = 5,
        CALL = 6,
        STICKER = 7,
        PRESENCE = 8,
        GIFT = 9,
        GROUPBOARD = 10,
        APPLINK = 11,
        LINK = 12,
        CONTACT = 13,
        FILE = 14,
        LOCATION = 15,
        POSTNOTIFICATION = 16,
        RICH = 17,
        CHATEVENT = 18,
        MUSIC = 19,
        PAYMENT = 20,
        EXTIMAGE = 21
    };

    enum class CustomMode : uint32_t {
        ENUM_NONE = UINT32_MAX,
        PROMOTION_FRIENDS_INVITE = 1,
        CAPABILITY_SERVER_SIDE_SMS = 2,
        LINE_CLIENT_ANALYTICS_CONFIGURATION = 3
    };

    enum class DeviceBooleanStateKey : uint32_t {
        ENUM_NONE = UINT32_MAX,
        BEACON_AGREEMENT = 1,
        BLUETOOTH = 2
    };

    enum class DeviceStringStateKey : uint32_t {
        ENUM_NONE = UINT32_MAX,
        LOCATION_OS = 1,
        LOCATION_APP = 2
    };

    enum class Diff : uint32_t {
        ENUM_NONE = UINT32_MAX,
        ADDED = 0,
        UPDATED = 1,
        REMOVED = 2
    };

    enum class EmailConfirmationStatus : uint32_t {
        ENUM_NONE = UINT32_MAX,
        NOT_SPECIFIED = 0,
        NOT_YET = 1,
        DONE = 3,
        NEED_ENFORCED_INPUT = 4
    };

    enum class EmailConfirmationType : uint32_t {
        ENUM_NONE = UINT32_MAX,
        SERVER_SIDE_EMAIL = 0,
        CLIENT_SIDE_EMAIL = 1
    };

    enum class ErrorCode : uint32_t {
        ENUM_NONE = UINT32_MAX,
        ILLEGAL_ARGUMENT = 0,
        AUTHENTICATION_FAILED = 1,
        DB_FAILED = 2,
        INVALID_STATE = 3,
        EXCESSIVE_ACCESS = 4,
        NOT_FOUND = 5,
        INVALID_MID = 9,
        NOT_A_MEMBER = 10,
        INVALID_LENGTH = 6,
        NOT_AVAILABLE_USER = 7,
        NOT_AUTHORIZED_DEVICE = 8,
        NOT_AUTHORIZED_SESSION = 14,
        INCOMPATIBLE_APP_VERSION = 11,
        NOT_READY = 12,
        NOT_AVAILABLE_SESSION = 13,
        SYSTEM_ERROR = 15,
        NO_AVAILABLE_VERIFICATION_METHOD = 16,
        NOT_AUTHENTICATED = 17,
        INVALID_IDENTITY_CREDENTIAL = 18,
        NOT_AVAILABLE_IDENTITY_IDENTIFIER = 19,
        INTERNAL_ERROR = 20,
        NO_SUCH_IDENTITY_IDENFIER = 21,
        DEACTIVATED_ACCOUNT_BOUND_TO_THIS_IDENTITY = 22,
        ILLEGAL_IDENTITY_CREDENTIAL = 23,
        UNKNOWN_CHANNEL = 24,
        NO_SUCH_MESSAGE_BOX = 25,
        NOT_AVAILABLE_MESSAGE_BOX = 26,
        CHANNEL_DOES_NOT_MATCH = 27,
        NOT_YOUR_MESSAGE = 28,
        MESSAGE_DEFINED_ERROR = 29,
        USER_CANNOT_ACCEPT_PRESENTS = 30,
        USER_NOT_STICKER_OWNER = 32,
        MAINTENANCE_ERROR = 33,
        ACCOUNT_NOT_MATCHED = 34,
        ABUSE_BLOCK = 35,
        NOT_FRIEND = 36,
        NOT_ALLOWED_CALL = 37,
        BLOCK_FRIEND = 38,
        INCOMPATIBLE_VOIP_VERSION = 39,
        INVALID_SNS_ACCESS_TOKEN = 40,
        EXTERNAL_SERVICE_NOT_AVAILABLE = 41,
        NOT_ALLOWED_ADD_CONTACT = 42,
        NOT_CERTIFICATED = 43,
        NOT_ALLOWED_SECONDARY_DEVICE = 44,
        INVALID_PIN_CODE = 45,
        NOT_FOUND_IDENTITY_CREDENTIAL = 46,
        EXCEED_FILE_MAX_SIZE = 47,
        EXCEED_DAILY_QUOTA = 48,
        NOT_SUPPORT_SEND_FILE = 49,
        MUST_UPGRADE = 50,
        NOT_AVAILABLE_PIN_CODE_SESSION = 51,
        EXPIRED_REVISION = 52,
        NOT_YET_PHONE_NUMBER = 54,
        BAD_CALL_NUMBER = 55,
        UNAVAILABLE_CALL_NUMBER = 56,
        NOT_SUPPORT_CALL_SERVICE = 57,
        CONGESTION_CONTROL = 58,
        NO_BALANCE = 59,
        NOT_PERMITTED_CALLER_ID = 60,
        NO_CALLER_ID_LIMIT_EXCEEDED = 61,
        CALLER_ID_VERIFICATION_REQUIRED = 62,
        NO_CALLER_ID_LIMIT_EXCEEDED_AND_VERIFICATION_REQUIRED = 63,
        MESSAGE_NOT_FOUND = 64,
        INVALID_ACCOUNT_MIGRATION_PINCODE_FORMAT = 65,
        ACCOUNT_MIGRATION_PINCODE_NOT_MATCHED = 66,
        ACCOUNT_MIGRATION_PINCODE_BLOCKED = 67,
        INVALID_PASSWORD_FORMAT = 69,
        FEATURE_RESTRICTED = 70,
        MESSAGE_NOT_DESTRUCTIBLE = 71,
        PAID_CALL_REDEEM_FAILED = 72,
        PREVENTED_JOIN_BY_TICKET = 73,
        SEND_MESSAGE_NOT_PERMITTED_FROM_LINE_AT = 75,
        SEND_MESSAGE_NOT_PERMITTED_WHILE_AUTO_REPLY = 76,
        SECURITY_CENTER_NOT_VERIFIED = 77,
        SECURITY_CENTER_BLOCKED_BY_SETTING = 78,
        SECURITY_CENTER_BLOCKED = 79,
        TALK_PROXY_EXCEPTION = 80,
        E2EE_INVALID_PROTOCOL = 81,
        E2EE_RETRY_ENCRYPT = 82,
        E2EE_UPDATE_SENDER_KEY = 83,
        E2EE_UPDATE_RECEIVER_KEY = 84,
        E2EE_INVALID_ARGUMENT = 85,
        E2EE_INVALID_VERSION = 86,
        E2EE_SENDER_DISABLED = 87,
        E2EE_RECEIVER_DISABLED = 88,
        E2EE_SENDER_NOT_ALLOWED = 89,
        E2EE_RECEIVER_NOT_ALLOWED = 90,
        E2EE_RESEND_FAIL = 91,
        E2EE_RESEND_OK = 92,
        HITOKOTO_BACKUP_NO_AVAILABLE_DATA = 93,
        E2EE_UPDATE_PRIMARY_DEVICE = 94,
        SUCCESS = 95,
        CANCEL = 96,
        E2EE_PRIMARY_NOT_SUPPORT = 97,
        E2EE_RETRY_PLAIN = 98,
        E2EE_RECREATE_GROUP_KEY = 99,
        E2EE_GROUP_TOO_MANY_MEMBERS = 100,
        SERVER_BUSY = 101,
        NOT_ALLOWED_ADD_FOLLOW = 102,
        INCOMING_FRIEND_REQUEST_LIMIT = 103,
        OUTGOING_FRIEND_REQUEST_LIMIT = 104,
        OUTGOING_FRIEND_REQUEST_QUOTA = 105,
        DUPLICATED = 106,
        BANNED = 107
    };

    enum class ExtendedProfileAttribute : uint32_t {
        ENUM_NONE = UINT32_MAX
    };

    enum class FeatureType : uint32_t {
        ENUM_NONE = UINT32_MAX,
        OBS_VIDEO = 1,
        OBS_GENERAL = 2
    };

    enum class FriendRequestDirection : uint32_t {
        ENUM_NONE = UINT32_MAX,
        INCOMING = 1,
        OUTGOING = 2
    };

    enum class FriendRequestMethod : uint32_t {
        ENUM_NONE = UINT32_MAX,
        TIMELINE = 1,
        NEARBY = 2,
        SQUARE = 3
    };

    enum class FriendRequestStatus : uint32_t {
        ENUM_NONE = UINT32_MAX,
        NONE = 0,
        AVAILABLE = 1,
        ALREADY_REQUESTED = 2,
        UNAVAILABLE = 3
    };

    enum class GroupAttribute : uint32_t {
        ENUM_NONE = UINT32_MAX,
        ALL = 255,
        NAME = 1,
        PICTURE_STATUS = 2,
        PREVENTED_JOIN_BY_TICKET = 4,
        NOTIFICATION_SETTING = 8
    };

    enum class GroupCallMediaType : uint32_t {
        ENUM_NONE = UINT32_MAX,
        AUDIO = 1,
        VIDEO = 2
    };

    enum class GroupPreferenceAttribute : uint32_t {
        ENUM_NONE = UINT32_MAX,
        INVITATION_TICKET = 1,
        FAVORITE_TIMESTAMP = 2
    };

    enum class IdentityProvider : uint32_t {
        ENUM_NONE = UINT32_MAX,
        UNKNOWN = 0,
        LINE = 1,
        NAVER_KR = 2,
        LINE_PHONE = 3
    };

    enum class LoginResultType : uint32_t {
        ENUM_NONE = UINT32_MAX,
        SUCCESS = 1,
        REQUIRE_QRCODE = 2,
        REQUIRE_DEVICE_CONFIRM = 3,
        REQUIRE_SMS_CONFIRM = 4
    };

    enum class LoginType : uint32_t {
        ENUM_NONE = UINT32_MAX,
        ID_CREDENTIAL = 0,
        QRCODE = 1,
        ID_CREDENTIAL_WITH_E2EE = 2
    };

    enum class MessageRelationType : uint32_t {
        ENUM_NONE = UINT32_MAX,
        FORWARD = 0,
        AUTO_REPLY = 1,
        SUBORDINATE = 2,
        REPLY = 3
    };

    enum class MIDType : uint32_t {
        ENUM_NONE = UINT32_MAX,
        USER = 0,
        ROOM = 1,
        GROUP = 2,
        SQUARE = 3,
        SQUARE_CHAT = 4,
        SQUARE_MEMBER = 5
    };

    enum class ModificationType : uint32_t {
        ENUM_NONE = UINT32_MAX,
        ADD = 0,
        REMOVE = 1,
        MODIFY = 2
    };

    enum class NotificationItemFetchMode : uint32_t {
        ENUM_NONE = UINT32_MAX,
        ALL = 0,
        APPEND = 1
    };

    enum class NotificationStatus : uint32_t {
        ENUM_NONE = UINT32_MAX,
        NOTIFICATION_ITEM_EXIST = 1,
        TIMELINE_ITEM_EXIST = 2,
        NOTE_GROUP_NEW_ITEM_EXIST = 4,
        TIMELINE_BUDDYGROUP_CHANGED = 8,
        NOTE_ONE_TO_ONE_NEW_ITEM_EXIST = 16,
        ALBUM_ITEM_EXIST = 32,
        TIMELINE_ITEM_DELETED = 64,
        OTOGROUP_ITEM_EXIST = 128,
        GROUPHOME_NEW_ITEM_EXIST = 256,
        GROUPHOME_HIDDEN_ITEM_CHANGED = 512,
        NOTIFICATION_ITEM_CHANGED = 1024,
        BEAD_ITEM_HIDE = 2048,
        BEAD_ITEM_SHOW = 4096
    };

    enum class NotificationType : uint32_t {
        ENUM_NONE = UINT32_MAX,
        APPLE_APNS = 1,
        GOOGLE_C2DM = 2,
        NHN_NNI = 3,
        SKT_AOM = 4,
        MS_MPNS = 5,
        RIM_BIS = 6,
        GOOGLE_GCM = 7,
        NOKIA_NNAPI = 8,
        TIZEN = 9,
        MOZILLA_SIMPLE = 10,
        LINE_BOT = 17,
        LINE_WAP = 18,
        APPLE_APNS_VOIP = 19,
        MS_WNS = 20
    };

    enum class OpStatus : uint32_t {
        ENUM_NONE = UINT32_MAX,
        NORMAL = 0,
        ALERT_DISABLED = 1,
        ALWAYS = 2
    };

    enum class OpType : uint32_t {
        ENUM_NONE = UINT32_MAX,
        END_OF_OPERATION = 0,
        UPDATE_PROFILE = 1,
        UPDATE_SETTINGS = 36,
        NOTIFIED_UPDATE_PROFILE = 2,
        REGISTER_USERID = 3,
        ADD_CONTACT = 4,
        NOTIFIED_ADD_CONTACT = 5,
        BLOCK_CONTACT = 6,
        UNBLOCK_CONTACT = 7,
        NOTIFIED_RECOMMEND_CONTACT = 8,
        CREATE_GROUP = 9,
        UPDATE_GROUP = 10,
        NOTIFIED_UPDATE_GROUP = 11,
        INVITE_INTO_GROUP = 12,
        NOTIFIED_INVITE_INTO_GROUP = 13,
        CANCEL_INVITATION_GROUP = 31,
        NOTIFIED_CANCEL_INVITATION_GROUP = 32,
        LEAVE_GROUP = 14,
        NOTIFIED_LEAVE_GROUP = 15,
        ACCEPT_GROUP_INVITATION = 16,
        NOTIFIED_ACCEPT_GROUP_INVITATION = 17,
        REJECT_GROUP_INVITATION = 34,
        NOTIFIED_REJECT_GROUP_INVITATION = 35,
        KICKOUT_FROM_GROUP = 18,
        NOTIFIED_KICKOUT_FROM_GROUP = 19,
        CREATE_ROOM = 20,
        INVITE_INTO_ROOM = 21,
        NOTIFIED_INVITE_INTO_ROOM = 22,
        LEAVE_ROOM = 23,
        NOTIFIED_LEAVE_ROOM = 24,
        SEND_MESSAGE = 25,
        RECEIVE_MESSAGE = 26,
        SEND_MESSAGE_RECEIPT = 27,
        RECEIVE_MESSAGE_RECEIPT = 28,
        SEND_CONTENT_RECEIPT = 29,
        SEND_CHAT_CHECKED = 40,
        SEND_CHAT_REMOVED = 41,
        RECEIVE_ANNOUNCEMENT = 30,
        INVITE_VIA_EMAIL = 38,
        NOTIFIED_REGISTER_USER = 37,
        NOTIFIED_UNREGISTER_USER = 33,
        NOTIFIED_REQUEST_RECOVERY = 39,
        NOTIFIED_FORCE_SYNC = 42,
        SEND_CONTENT = 43,
        SEND_MESSAGE_MYHOME = 44,
        NOTIFIED_UPDATE_CONTENT_PREVIEW = 45,
        REMOVE_ALL_MESSAGES = 46,
        NOTIFIED_UPDATE_PURCHASES = 47,
        DUMMY = 48,
        UPDATE_CONTACT = 49,
        NOTIFIED_RECEIVED_CALL = 50,
        CANCEL_CALL = 51,
        NOTIFIED_REDIRECT = 52,
        NOTIFIED_CHANNEL_SYNC = 53,
        FAILED_SEND_MESSAGE = 54,
        NOTIFIED_READ_MESSAGE = 55,
        FAILED_EMAIL_CONFIRMATION = 56,
        NOTIFIED_PUSH_NOTICENTER_ITEM = 59,
        NOTIFIED_CHAT_CONTENT = 58,
        NOTIFIED_JOIN_CHAT = 60,
        NOTIFIED_LEAVE_CHAT = 61,
        NOTIFIED_TYPING = 62,
        FRIEND_REQUEST_ACCEPTED = 63,
        DESTROY_MESSAGE = 64,
        NOTIFIED_DESTROY_MESSAGE = 65,
        UPDATE_PUBLICKEYCHAIN = 66,
        NOTIFIED_UPDATE_PUBLICKEYCHAIN = 67,
        NOTIFIED_BLOCK_CONTACT = 68,
        NOTIFIED_UNBLOCK_CONTACT = 69,
        UPDATE_GROUPPREFERENCE = 70,
        NOTIFIED_PAYMENT_EVENT = 71,
        REGISTER_E2EE_PUBLICKEY = 72,
        NOTIFIED_E2EE_KEY_EXCHANGE_REQ = 73,
        NOTIFIED_E2EE_KEY_EXCHANGE_RESP = 74,
        NOTIFIED_E2EE_MESSAGE_RESEND_REQ = 75,
        NOTIFIED_E2EE_MESSAGE_RESEND_RESP = 76,
        NOTIFIED_E2EE_KEY_UPDATE = 77,
        NOTIFIED_BUDDY_UPDATE_PROFILE = 78,
        NOTIFIED_UPDATE_LINEAT_TABS = 79,
        UPDATE_ROOM = 80,
        NOTIFIED_BEACON_DETECTED = 81,
        UPDATE_EXTENDED_PROFILE = 82,
        ADD_FOLLOW = 83,
        NOTIFIED_ADD_FOLLOW = 84,
        DELETE_FOLLOW = 85,
        NOTIFIED_DELETE_FOLLOW = 86,
        UPDATE_TIMELINE_SETTINGS = 87,
        NOTIFIED_FRIEND_REQUEST = 88,
        UPDATE_RINGBACK_TONE = 89,
        NOTIFIED_POSTBACK = 90,
        RECEIVE_READ_WATERMARK = 91,
        NOTIFIED_MESSAGE_DELIVERED = 92
    };

    enum class PaidCallerIdStatus : uint32_t {
        ENUM_NONE = UINT32_MAX,
        NOT_SPECIFIED = 0,
        VALID = 1,
        VERIFICATION_REQUIRED = 2,
        NOT_PERMITTED = 3,
        LIMIT_EXCEEDED = 4,
        LIMIT_EXCEEDED_AND_VERIFICATION_REQUIRED = 5
    };

    enum class PaidCallProductType : uint32_t {
        ENUM_NONE = UINT32_MAX,
        COIN = 0,
        CREDIT = 1,
        MONTHLY = 2
    };

    enum class PaidCallType : uint32_t {
        ENUM_NONE = UINT32_MAX,
        OUT = 0,
        IN = 1,
        TOLLFREE = 2,
        RECORD = 3,
        AD = 4,
        CS = 5
    };

    enum class PayloadType : uint32_t {
        ENUM_NONE = UINT32_MAX,
        PAYLOAD_BUY = 101,
        PAYLOAD_CS = 111,
        PAYLOAD_BONUS = 121,
        PAYLOAD_EVENT = 131,
        PAYLOAD_POINT_AUTO_EXCHANGED = 141,
        PAYLOAD_POINT_MANUAL_EXCHANGED = 151
    };

    enum class PaymentPgType : uint32_t {
        ENUM_NONE = UINT32_MAX,
        PAYMENT_PG_NONE = 0,
        PAYMENT_PG_AU = 1,
        PAYMENT_PG_AL = 2
    };

    enum class PaymentType : uint32_t {
        ENUM_NONE = UINT32_MAX,
        PAYMENT_APPLE = 1,
        PAYMENT_GOOGLE = 2
    };

    enum class PersonalInfo : uint32_t {
        ENUM_NONE = UINT32_MAX,
        EMAIL = 0,
        PHONE = 1,
        BIRTHDAY = 2,
        RAW_BIRTHDAY = 3
    };

    enum class PlaceSearchProvider : uint32_t {
        ENUM_NONE = UINT32_MAX,
        GOOGLE = 0,
        BAIDU = 1
    };

    enum class PointErrorCode : uint32_t {
        ENUM_NONE = UINT32_MAX,
        REQUEST_DUPLICATION = 3001,
        INVALID_PARAMETER = 3002,
        NOT_ENOUGH_BALANCE = 3003,
        AUTHENTICATION_FAIL = 3004,
        API_ACCESS_FORBIDDEN = 3005,
        MEMBER_ACCOUNT_NOT_FOUND = 3006,
        SERVICE_ACCOUNT_NOT_FOUND = 3007,
        TRANSACTION_NOT_FOUND = 3008,
        ALREADY_REVERSED_TRANSACTION = 3009,
        MESSAGE_NOT_READABLE = 3010,
        HTTP_REQUEST_METHOD_NOT_SUPPORTED = 3011,
        HTTP_MEDIA_TYPE_NOT_SUPPORTED = 3012,
        NOT_ALLOWED_TO_DEPOSIT = 3013,
        NOT_ALLOWED_TO_PAY = 3014,
        TRANSACTION_ACCESS_FORBIDDEN = 3015,
        INVALID_SERVICE_CONFIGURATION = 4001,
        DCS_COMMUNICATION_FAIL = 5004,
        UPDATE_BALANCE_FAIL = 5007,
        SYSTEM_ERROR = 5999,
        SYSTEM_MAINTENANCE = 5888
    };

    enum class PrivacyLevelType : uint32_t {
        ENUM_NONE = UINT32_MAX,
        PUBLIC = 0,
        PRIVATE = 1
    };

    enum class ProductBannerLinkType : uint32_t {
        ENUM_NONE = UINT32_MAX,
        BANNER_LINK_NONE = 0,
        BANNER_LINK_ITEM = 1,
        BANNER_LINK_URL = 2,
        BANNER_LINK_CATEGORY = 3
    };

    enum class ProductEventType : uint32_t {
        ENUM_NONE = UINT32_MAX,
        NO_EVENT = 0,
        CARRIER_ANY = 65537,
        BUDDY_ANY = 131073,
        INSTALL_IOS = 196609,
        INSTALL_ANDROID = 196610,
        MISSION_ANY = 262145,
        MUSTBUY_ANY = 327681
    };

    enum class PublicKeychainStatus : uint32_t {
        ENUM_NONE = UINT32_MAX,
        UPDATED = 0,
        DELETED = 1,
        RESTRICTED = 2
    };

    enum class PublicType : uint32_t {
        ENUM_NONE = UINT32_MAX,
        HIDDEN = 0,
        PUBLIC = 1000
    };

    enum class RedirectType : uint32_t {
        ENUM_NONE = UINT32_MAX,
        NONE = 0,
        EXPIRE_SECOND = 1
    };

    enum class RegistrationType : uint32_t {
        ENUM_NONE = UINT32_MAX,
        PHONE = 0,
        EMAIL_WAP = 1,
        FACEBOOK = 2305,
        SINA = 2306,
        RENREN = 2307,
        FEIXIN = 2308
    };

    enum class ReportCategory : uint32_t {
        ENUM_NONE = UINT32_MAX,
        PUSH_NORMAL_PLAIN = 0,
        PUSH_NORMAL_E2EE = 1,
        PUSH_VOIP_PLAIN = 2,
        PUSH_VOIP_E2EE = 3
    };

    enum class ReservedMessageSessionId : uint32_t {
        ENUM_NONE = UINT32_MAX,
        DEFAULT = 0,
        HIDDEN_CHAT = 1
    };

    enum class RoomAttribute : uint32_t {
        ENUM_NONE = UINT32_MAX,
        ALL = 255,
        NOTIFICATION_SETTING = 1
    };

    enum class SecurityCenterSettingsType : uint32_t {
        ENUM_NONE = UINT32_MAX,
        NOT_APPLICABLE = 0,
        NOT_SET = 1,
        SET = 2,
        NEED_ENFORCED_INPUT = 3
    };

    enum class ServiceCode : uint32_t {
        ENUM_NONE = UINT32_MAX,
        UNKNOWN = 0,
        TALK = 1,
        SQUARE = 2
    };

    enum class SettingsAttribute : uint32_t {
        ENUM_NONE = UINT32_MAX,
        NOTIFICATION_ENABLE = 1,
        NOTIFICATION_MUTE_EXPIRATION = 2,
        NOTIFICATION_NEW_MESSAGE = 4,
        NOTIFICATION_GROUP_INVITATION = 8,
        NOTIFICATION_SHOW_MESSAGE = 16,
        NOTIFICATION_INCOMING_CALL = 32,
        NOTIFICATION_SOUND_MESSAGE = 256,
        NOTIFICATION_SOUND_GROUP = 512,
        NOTIFICATION_DISABLED_WITH_SUB = 65536,
        NOTIFICATION_PAYMENT = 131072,
        PRIVACY_SYNC_CONTACTS = 64,
        PRIVACY_SEARCH_BY_PHONE_NUMBER = 128,
        PRIVACY_SEARCH_BY_USERID = 8192,
        PRIVACY_SEARCH_BY_EMAIL = 16384,
        PRIVACY_ALLOW_SECONDARY_DEVICE_LOGIN = 2097152,
        PRIVACY_PROFILE_IMAGE_POST_TO_MYHOME = 8388608,
        PRIVACY_ALLOW_FRIEND_REQUEST = 1073741824,
        PRIVACY_RECV_MESSAGES_FROM_NOT_FRIEND = 33554432,
        PRIVACY_AGREE_USE_LINECOIN_TO_PAIDCALL = 67108864,
        PRIVACY_AGREE_USE_PAIDCALL = 134217728,
        CONTACT_MY_TICKET = 1024,
        IDENTITY_PROVIDER = 2048,
        IDENTITY_IDENTIFIER = 4096,
        SNS_ACCOUNT = 524288,
        PHONE_REGISTRATION = 1048576,
        PREFERENCE_LOCALE = 32768,
        CUSTOM_MODE = 4194304,
        EMAIL_CONFIRMATION_STATUS = 16777216,
        ACCOUNT_MIGRATION_PINCODE = 268435456,
        ENFORCED_INPUT_ACCOUNT_MIGRATION_PINCODE = 536870912,
        SECURITY_CENTER_SETTINGS = 262144
    };

    enum class SettingsAttributeEx : uint32_t {
        ENUM_NONE = UINT32_MAX,
        NOTIFICATION_ENABLE = 0,
        NOTIFICATION_MUTE_EXPIRATION = 1,
        NOTIFICATION_NEW_MESSAGE = 2,
        NOTIFICATION_GROUP_INVITATION = 3,
        NOTIFICATION_SHOW_MESSAGE = 4,
        NOTIFICATION_INCOMING_CALL = 5,
        NOTIFICATION_SOUND_MESSAGE = 8,
        NOTIFICATION_SOUND_GROUP = 9,
        NOTIFICATION_DISABLED_WITH_SUB = 16,
        NOTIFICATION_PAYMENT = 17,
        NOTIFICATION_MENTION = 40,
        PRIVACY_SYNC_CONTACTS = 6,
        PRIVACY_SEARCH_BY_PHONE_NUMBER = 7,
        PRIVACY_SEARCH_BY_USERID = 13,
        PRIVACY_SEARCH_BY_EMAIL = 14,
        PRIVACY_ALLOW_SECONDARY_DEVICE_LOGIN = 21,
        PRIVACY_PROFILE_IMAGE_POST_TO_MYHOME = 23,
        PRIVACY_PROFILE_MUSIC_POST_TO_MYHOME = 35,
        PRIVACY_ALLOW_FRIEND_REQUEST = 30,
        PRIVACY_RECV_MESSAGES_FROM_NOT_FRIEND = 25,
        PRIVACY_AGREE_USE_LINECOIN_TO_PAIDCALL = 26,
        PRIVACY_AGREE_USE_PAIDCALL = 27,
        CONTACT_MY_TICKET = 10,
        IDENTITY_PROVIDER = 11,
        IDENTITY_IDENTIFIER = 12,
        SNS_ACCOUNT = 19,
        PHONE_REGISTRATION = 20,
        PREFERENCE_LOCALE = 15,
        CUSTOM_MODE = 22,
        EMAIL_CONFIRMATION_STATUS = 24,
        ACCOUNT_MIGRATION_PINCODE = 28,
        ENFORCED_INPUT_ACCOUNT_MIGRATION_PINCODE = 29,
        SECURITY_CENTER_SETTINGS = 18,
        E2EE_ENABLE = 33,
        HITOKOTO_BACKUP_REQUESTED = 34,
        CONTACT_ALLOW_FOLLOWING = 36,
        PRIVACY_ALLOW_NEARBY = 37,
        AGREEMENT_NEARBY = 38,
        AGREEMENT_SQUARE = 39,
        ALLOW_UNREGISTRATION_SECONDARY_DEVICE = 41,
        AGREEMENT_BOT_USE = 42
    };

    enum class ProfileAttribute : uint32_t {
        ENUM_NONE = UINT32_MAX,
        ALL = 511,
        EMAIL = 1,
        DISPLAY_NAME = 2,
        PHONETIC_NAME = 4,
        PICTURE = 8,
        STATUS_MESSAGE = 16,
        ALLOW_SEARCH_BY_USERID = 32,
        ALLOW_SEARCH_BY_EMAIL = 64,
        BUDDY_STATUS = 128,
        MUSIC_PROFILE = 256
    };

    enum class SnsIdType : uint32_t {
        ENUM_NONE = UINT32_MAX,
        FACEBOOK = 1,
        SINA = 2,
        RENREN = 3,
        FEIXIN = 4,
        BBM = 5
    };

    enum class SpammerReason : uint32_t {
        ENUM_NONE = UINT32_MAX,
        OTHER = 0,
        ADVERTISING = 1,
        GENDER_HARASSMENT = 2,
        HARASSMENT = 3
    };

    enum class SpotCategory : uint32_t {
        ENUM_NONE = UINT32_MAX,
        UNKNOWN = 0,
        GOURMET = 1,
        BEAUTY = 2,
        TRAVEL = 3,
        SHOPPING = 4,
        ENTERTAINMENT = 5,
        SPORTS = 6,
        TRANSPORT = 7,
        LIFE = 8,
        HOSPITAL = 9,
        FINANCE = 10,
        EDUCATION = 11,
        OTHER = 12,
        ALL = 10000
    };

    enum class StickerResourceType : uint32_t {
        ENUM_NONE = UINT32_MAX,
        STATIC = 1,
        ANIMATION = 2,
        SOUND = 3,
        ANIMATION_SOUND = 4,
        POPUP = 5,
        POPUP_SOUND = 6
    };

    enum class SuggestDictionaryIncrementStatus : uint32_t {
        ENUM_NONE = UINT32_MAX,
        SUCCESS = 0,
        INVALID_REVISION = 1,
        TOO_LARGE_DATA = 2,
        SCHEME_CHANGED = 3,
        RETRY = 4,
        FAIL = 5,
        TOO_OLD_DATA = 6
    };

    enum class SyncActionType : uint32_t {
        ENUM_NONE = UINT32_MAX,
        SYNC = 0,
        REPORT = 1
    };

    enum class SyncCategory : uint32_t {
        ENUM_NONE = UINT32_MAX,
        PROFILE = 0,
        SETTINGS = 1,
        OPS = 2,
        CONTACT = 3,
        RECOMMEND = 4,
        BLOCK = 5,
        GROUP = 6,
        ROOM = 7,
        NOTIFICATION = 8,
        ADDRESS_BOOK = 9
    };

    enum class SyncTriggerReason : uint32_t {
        ENUM_NONE = UINT32_MAX,
        OTHER = 0,
        REVISION_GAP_TOO_LARGE = 1,
        OPERATION_EXPIRED = 2
    };

    enum class TMessageBoxStatus : uint32_t {
        ENUM_NONE = UINT32_MAX,
        ACTIVATED = 1,
        UNREAD = 2
    };

    enum class UserAgeType : uint32_t {
        ENUM_NONE = UINT32_MAX,
        OVER = 1,
        UNDER = 2,
        UNDEFINED = 3
    };

    enum class AccountMigrationCheckType : uint32_t {
        ENUM_NONE = UINT32_MAX,
        SKIP = 0,
        PINCODE = 1,
        SECURITY_CENTER = 2
    };

    enum class AccountMigrationPincodeType : uint32_t {
        ENUM_NONE = UINT32_MAX,
        NOT_APPLICABLE = 0,
        NOT_SET = 1,
        SET = 2,
        NEED_ENFORCED_INPUT = 3
    };

    enum class UserStatus : uint32_t {
        ENUM_NONE = UINT32_MAX,
        NORMAL = 0,
        UNBOUND = 1,
        UNREGISTERED = 2
    };

    enum class VerificationMethod : uint32_t {
        ENUM_NONE = UINT32_MAX,
        NO_AVAILABLE = 0,
        PIN_VIA_SMS = 1,
        CALLERID_INDIGO = 2,
        PIN_VIA_TTS = 4,
        SKIP = 10
    };

    enum class VerificationResult : uint32_t {
        ENUM_NONE = UINT32_MAX,
        FAILED = 0,
        OK_NOT_REGISTERED_YET = 1,
        OK_REGISTERED_WITH_SAME_DEVICE = 2,
        OK_REGISTERED_WITH_ANOTHER_DEVICE = 3
    };

    enum class WapInvitationType : uint32_t {
        ENUM_NONE = UINT32_MAX,
        REGISTRATION = 1,
        CHAT = 2
    };

    enum class TrackingType : uint32_t {
        ENUM_NONE = UINT32_MAX
    };

    enum class UnregistrationReason : uint32_t {
        ENUM_NONE = UINT32_MAX,
        UNREGISTRATION_REASON_UNREGISTER_USER = 1,
        UNREGISTRATION_REASON_UNBIND_DEVICE = 2
    };

    struct StickerIdRange {
        std::optional<uint64_t> start;
        std::optional<uint32_t> size;
        bool operator < (const StickerIdRange&) const { return false; }
    };

    struct ProductSimple {
        std::optional<std::string> productId;
        std::optional<uint64_t> packageId;
        std::optional<uint32_t> version;
        std::optional<bool> onSale;
        std::optional<uint64_t> validUntil;
        std::optional<std::vector<StickerIdRange>> stickerIdRanges;
        std::optional<bool> grantedByDefault;
        std::optional<uint32_t> displayOrder;
        bool operator < (const ProductSimple&) const { return false; }
    };

    struct Announcement {
        std::optional<uint32_t> index;
        std::optional<bool> forceUpdate;
        std::optional<std::string> title;
        std::optional<std::string> text;
        std::optional<uint64_t> createdTime;
        std::optional<std::string> pictureUrl;
        std::optional<std::string> thumbnailUrl;
        bool operator < (const Announcement&) const { return false; }
    };

    struct ChatRoomAnnouncementContents {
        std::optional<uint32_t> displayFields;
        std::optional<std::string> text;
        std::optional<std::string> link;
        std::optional<std::string> thumbnail;
        bool operator < (const ChatRoomAnnouncementContents&) const { return false; }
    };

    struct ChatRoomAnnouncement {
        std::optional<uint64_t> announcementSeq;
        std::optional<uint32_t> type;
        std::optional<ChatRoomAnnouncementContents> contents;
        std::optional<std::string> creatorMid;
        std::optional<uint64_t> createdTime;
        bool operator < (const ChatRoomAnnouncement&) const { return false; }
    };

    struct ChannelNotificationSetting {
        std::optional<std::string> channelId;
        std::optional<std::string> name;
        std::optional<bool> notificationReceivable;
        std::optional<bool> messageReceivable;
        std::optional<bool> showDefault;
        bool operator < (const ChannelNotificationSetting&) const { return false; }
    };

    struct ChannelProvider {
        std::optional<std::string> name;
        bool operator < (const ChannelProvider&) const { return false; }
    };

    struct ChannelSettings {
        std::optional<bool> unapprovedMessageReceivable;
        bool operator < (const ChannelSettings&) const { return false; }
    };

    struct AuthQrcode {
        std::optional<std::string> qrcode;
        std::optional<std::string> verifier;
        std::optional<std::string> callbackUrl;
        bool operator < (const AuthQrcode&) const { return false; }
    };

    struct Balance {
        std::optional<std::string> currentPointsFixedPointDecimal;
        bool operator < (const Balance&) const { return false; }
    };

    struct BanPage {
        std::optional<std::string> url;
        bool operator < (const BanPage&) const { return false; }
    };

    struct BeaconCondition {
        std::optional<std::string> inFriends;
        std::optional<std::string> notInFriends;
        std::optional<bool> termsAgreed;
        bool operator < (const BeaconCondition&) const { return false; }
    };

    struct BotUseInfo {
        std::optional<bool> botUseAgreementAccepted;
        std::optional<bool> botInFriends;
        std::optional<std::string> primaryApplication;
        std::optional<std::string> locale;
        bool operator < (const BotUseInfo&) const { return false; }
    };

    struct BuddyCategoryEntry {
        std::optional<std::string> classification;
        std::optional<std::string> displayName;
        std::optional<uint32_t> totalBuddyCount;
        bool operator < (const BuddyCategoryEntry&) const { return false; }
    };

    struct BuddyOnAirUrls {
        std::optional<std::map<std::string, std::string>> hls;
        std::optional<std::map<std::string, std::string>> smoothStreaming;
        bool operator < (const BuddyOnAirUrls&) const { return false; }
    };

    struct BuddyProfile {
        std::optional<std::string> buddyId;
        std::optional<std::string> mid;
        std::optional<std::string> searchId;
        std::optional<std::string> displayName;
        std::optional<std::string> statusMessage;
        std::optional<uint64_t> contactCount;
        bool operator < (const BuddyProfile&) const { return false; }
    };

    struct BuddyRichMenuChatBarItem {
        std::optional<std::string> label;
        std::optional<std::string> body;
        std::optional<bool> selected;
        bool operator < (const BuddyRichMenuChatBarItem&) const { return false; }
    };

    struct BuddyRichMenuContents {
        std::optional<std::string> body;
        bool operator < (const BuddyRichMenuContents&) const { return false; }
    };

    struct BuddySearchResult {
        std::optional<std::string> mid;
        std::optional<std::string> displayName;
        std::optional<std::string> pictureStatus;
        std::optional<std::string> picturePath;
        std::optional<std::string> statusMessage;
        std::optional<bool> businessAccount;
        std::optional<uint32_t> iconType;
        std::optional<BotType> botType;
        bool operator < (const BuddySearchResult&) const { return false; }
    };

    struct BuddyWebChatBarItem {
        std::optional<std::string> label;
        std::optional<std::string> url;
        bool operator < (const BuddyWebChatBarItem&) const { return false; }
    };

    struct BuddyWidget {
        std::optional<std::string> icon;
        std::optional<std::string> label;
        std::optional<std::string> url;
        bool operator < (const BuddyWidget&) const { return false; }
    };

    struct CallHost {
        std::optional<std::string> host;
        std::optional<uint32_t> port;
        std::optional<std::string> zone;
        bool operator < (const CallHost&) const { return false; }
    };

    struct BeaconTouchActions {
        std::optional<std::vector<std::string>> actions;
        bool operator < (const BeaconTouchActions&) const { return false; }
    };

    struct CoinProductItem {
        std::optional<std::string> itemId;
        std::optional<uint32_t> coin;
        std::optional<uint32_t> freeCoin;
        std::optional<std::string> currency;
        std::optional<std::string> price;
        std::optional<std::string> displayPrice;
        std::optional<std::string> name;
        std::optional<std::string> desc;
        bool operator < (const CoinProductItem&) const { return false; }
    };

    struct CoinUseReservationItem {
        std::optional<std::string> itemId;
        std::optional<std::string> itemName;
        std::optional<uint32_t> amount;
        bool operator < (const CoinUseReservationItem&) const { return false; }
    };

    struct CommitSendMessagesToMidRequest {
        std::optional<uint32_t> seq;
        std::optional<std::vector<std::string>> messageIds;
        bool operator < (const CommitSendMessagesToMidRequest&) const { return false; }
    };

    struct CommitSendMessagesToMidResponse {
        std::optional<uint64_t> successCount;
        std::optional<uint64_t> failCount;
        std::optional<uint64_t> unregisterCount;
        std::optional<uint64_t> blockCount;
        bool operator < (const CommitSendMessagesToMidResponse&) const { return false; }
    };

    struct Configurations {
        std::optional<uint64_t> revision;
        std::optional<std::map<std::string, std::string>> configMap;
        bool operator < (const Configurations&) const { return false; }
    };

    struct ContactReportResult {
        std::optional<std::string> mid;
        std::optional<bool> exists;
        bool operator < (const ContactReportResult&) const { return false; }
    };

    struct E2EEKey {
        std::optional<uint32_t> version;
        std::optional<uint32_t> keyId;
        std::optional<std::string> publicKey;
        std::optional<std::string> privateKey;
        std::optional<uint64_t> createdTime;
        bool operator < (const E2EEKey&) const { return false; }
    };

    struct E2EEPublicKey {
        std::optional<uint32_t> version;
        std::optional<uint32_t> keyId;
        std::optional<std::string> keyData;
        std::optional<uint64_t> createdTime;
        bool operator < (const E2EEPublicKey&) const { return false; }
    };

    struct EmailConfirmation {
        std::optional<bool> usePasswordSet;
        std::optional<std::string> email;
        std::optional<std::string> password;
        std::optional<bool> ignoreDuplication;
        std::optional<bool> useEmailOnly;
        bool operator < (const EmailConfirmation&) const { return false; }
    };

    struct EmailConfirmationResult {
        std::optional<std::string> certificate;
        bool operator < (const EmailConfirmationResult&) const { return false; }
    };

    struct FriendChannelMatrix {
        std::optional<std::string> channelId;
        std::optional<std::string> representMid;
        std::optional<uint32_t> count;
        std::optional<uint32_t> point;
        bool operator < (const FriendChannelMatrix&) const { return false; }
    };

    struct GetBalanceRequest {
        bool operator < (const GetBalanceRequest&) const { return false; }
    };

    struct Geolocation {
        std::optional<double> longitude;
        std::optional<double> latitude;
        bool operator < (const Geolocation&) const { return false; }
    };

    struct GetTotalCoinBalanceResponse {
        std::optional<std::string> totalBalance;
        std::optional<std::string> paidCoinBalance;
        std::optional<std::string> freeCoinBalance;
        std::optional<std::string> rewardCoinBalance;
        std::optional<std::string> expectedAutoExchangedCoinBalance;
        bool operator < (const GetTotalCoinBalanceResponse&) const { return false; }
    };

    struct ChannelDomain {
        std::optional<std::string> host;
        std::optional<bool> removed;
        bool operator < (const ChannelDomain&) const { return false; }
    };

    struct ChannelToken {
        std::optional<std::string> token;
        std::optional<std::string> obsToken;
        std::optional<uint64_t> expiration;
        std::optional<std::string> refreshToken;
        std::optional<std::string> channelAccessToken;
        bool operator < (const ChannelToken&) const { return false; }
    };

    struct ClientLastStatus {
        std::optional<uint64_t> lastRev;
        std::optional<uint32_t> badgeCount;
        bool operator < (const ClientLastStatus&) const { return false; }
    };

    struct Coin {
        std::optional<uint32_t> freeCoinBalance;
        std::optional<uint32_t> payedCoinBalance;
        std::optional<uint32_t> totalCoinBalance;
        std::optional<uint32_t> rewardCoinBalance;
        bool operator < (const Coin&) const { return false; }
    };

    struct ChannelIdWithLastUpdated {
        std::optional<std::string> channelId;
        std::optional<uint64_t> lastUpdated;
        bool operator < (const ChannelIdWithLastUpdated&) const { return false; }
    };

    struct GroupPreference {
        std::optional<std::string> invitationTicket;
        std::optional<uint64_t> favoriteTimestamp;
        bool operator < (const GroupPreference&) const { return false; }
    };

    struct Location {
        std::optional<std::string> title;
        std::optional<std::string> address;
        std::optional<double> latitude;
        std::optional<double> longitude;
        std::optional<std::string> phone;
        bool operator < (const Location&) const { return false; }
    };

    struct MessageBoxV2MessageId {
        std::optional<uint64_t> deliveredTime;
        std::optional<uint64_t> messageId;
        bool operator < (const MessageBoxV2MessageId&) const { return false; }
    };

    struct MessageStoreResult {
        std::optional<std::string> requestId;
        std::optional<std::vector<std::string>> messageIds;
        bool operator < (const MessageStoreResult&) const { return false; }
    };

    struct ChannelInfo {
        std::optional<std::string> channelId;
        std::optional<std::string> name;
        std::optional<std::string> entryPageUrl;
        std::optional<std::string> descriptionText;
        std::optional<ChannelProvider> provider;
        std::optional<PublicType> publicType;
        std::optional<std::string> iconImage;
        std::optional<std::vector<std::string>> permissions;
        std::optional<std::string> iconThumbnailImage;
        std::optional<std::vector<ChannelConfiguration>> channelConfigurations;
        std::optional<bool> lcsAllApiUsable;
        std::optional<std::set<ChannelPermission>> allowedPermissions;
        std::optional<std::vector<ChannelDomain>> channelDomains;
        std::optional<uint64_t> updatedTimestamp;
        bool operator < (const ChannelInfo&) const { return false; }
    };

    struct ApprovedChannelInfo {
        std::optional<ChannelInfo> channelInfo;
        std::optional<uint64_t> approvedAt;
        bool operator < (const ApprovedChannelInfo&) const { return false; }
    };

    struct ApprovedChannelInfos {
        std::optional<std::vector<ApprovedChannelInfo>> approvedChannelInfos;
        std::optional<uint64_t> revision;
        bool operator < (const ApprovedChannelInfos&) const { return false; }
    };

    struct BeaconBackgroundNotification {
        std::optional<uint64_t> actionInterval;
        std::optional<std::vector<BeaconCondition>> actionAndConditions;
        std::optional<uint64_t> actionDelay;
        std::optional<std::vector<std::vector<BeaconCondition>>> actionConditions;
        bool operator < (const BeaconBackgroundNotification&) const { return false; }
    };

    struct BeaconLayerInfoAndActions {
        std::optional<std::string> pictureUrl;
        std::optional<std::string> label;
        std::optional<std::string> text;
        std::optional<std::vector<std::string>> actions;
        std::optional<std::vector<BeaconCondition>> showOrConditions;
        std::optional<std::vector<std::vector<BeaconCondition>>> showConditions;
        std::optional<uint64_t> timeToHide;
        bool operator < (const BeaconLayerInfoAndActions&) const { return false; }
    };

    struct BeaconQueryResponse {
        std::optional<std::vector<std::string>> deprecated_actionUrls;
        std::optional<uint64_t> cacheTtl;
        std::optional<BeaconTouchActions> touchActions;
        std::optional<BeaconLayerInfoAndActions> layerInfoAndActions;
        std::optional<BeaconBackgroundNotification> backgroundEnteringNotification;
        std::optional<BeaconBackgroundNotification> backgroundLeavingNotification;
        std::optional<std::string> group;
        std::optional<std::string> major;
        std::optional<std::string> minor;
        std::optional<double> effectiveRange;
        std::optional<std::vector<std::string>> channelWhiteList;
        bool operator < (const BeaconQueryResponse&) const { return false; }
    };

    struct BuddyBanner {
        std::optional<BuddyBannerLinkType> buddyBannerLinkType;
        std::optional<std::string> buddyBannerLink;
        std::optional<std::string> buddyBannerImageUrl;
        std::optional<uint32_t> width;
        std::optional<uint32_t> height;
        std::optional<uint64_t> bannerId;
        bool operator < (const BuddyBanner&) const { return false; }
    };

    struct BuddyCategoryView {
        std::optional<std::vector<BuddyCategoryEntry>> categoryEntries;
        bool operator < (const BuddyCategoryView&) const { return false; }
    };

    struct BuddyWidgetListCharBarItem {
        std::optional<std::string> label;
        std::optional<std::vector<BuddyWidget>> widgets;
        std::optional<bool> selected;
        bool operator < (const BuddyWidgetListCharBarItem&) const { return false; }
    };

    struct BuddyChatBarItem {
        std::optional<BuddyRichMenuChatBarItem> rich;
        std::optional<BuddyWidgetListCharBarItem> widgetList;
        std::optional<BuddyWebChatBarItem> web;
        bool operator < (const BuddyChatBarItem&) const { return false; }
    };

    struct Contact {
        std::optional<std::string> mid;
        std::optional<uint64_t> createdTime;
        std::optional<ContactType> type;
        std::optional<ContactStatus> status;
        std::optional<ContactRelation> relation;
        std::optional<std::string> displayName;
        std::optional<std::string> phoneticName;
        std::optional<std::string> pictureStatus;
        std::optional<std::string> thumbnailUrl;
        std::optional<std::string> statusMessage;
        std::optional<std::string> displayNameOverridden;
        std::optional<uint64_t> favoriteTime;
        std::optional<bool> capableVoiceCall;
        std::optional<bool> capableVideoCall;
        std::optional<bool> capableMyhome;
        std::optional<bool> capableBuddy;
        std::optional<uint32_t> attributes;
        std::optional<uint64_t> settings;
        std::optional<std::string> picturePath;
        std::optional<std::string> recommendParams;
        std::optional<FriendRequestStatus> friendRequestStatus;
        std::optional<std::string> musicProfile;
        std::optional<std::string> videoProfile;
        bool operator < (const Contact&) const { return false; }
    };

    struct BuddyChatBar {
        std::optional<std::vector<BuddyChatBarItem>> barItems;
        bool operator < (const BuddyChatBar&) const { return false; }
    };

    struct BuddyCollectionEntry {
        std::optional<Contact> contact;
        std::optional<bool> onAir;
        std::optional<bool> asNew;
        bool operator < (const BuddyCollectionEntry&) const { return false; }
    };

    struct BuddyCollection {
        std::optional<uint32_t> code;
        std::optional<std::string> displayName;
        std::optional<uint32_t> totalBuddyCount;
        std::optional<std::vector<BuddyCollectionEntry>> entries;
        std::optional<bool> horizontal;
        std::optional<BuddyCollectionType> type;
        bool operator < (const BuddyCollection&) const { return false; }
    };

    struct BuddyDetail {
        std::optional<std::string> mid;
        std::optional<uint64_t> memberCount;
        std::optional<bool> onAir;
        std::optional<bool> businessAccount;
        std::optional<bool> addable;
        std::optional<std::set<ContentType>> acceptableContentTypes;
        std::optional<bool> capableMyhome;
        std::optional<bool> freePhoneCallable;
        std::optional<std::string> phoneNumberToDial;
        std::optional<bool> needPermissionApproval;
        std::optional<uint32_t> channelId;
        std::optional<std::string> channelProviderName;
        std::optional<uint32_t> iconType;
        std::optional<BotType> botType;
        std::optional<bool> showRichMenu;
        std::optional<uint64_t> richMenuRevision;
        std::optional<BuddyOnAirLabel> onAirLabel;
        std::optional<bool> useTheme;
        std::optional<std::string> themeId;
        std::optional<bool> useBar;
        std::optional<uint64_t> barRevision;
        std::optional<bool> useBackground;
        std::optional<std::string> backgroundId;
        std::optional<bool> statusBarEnabled;
        std::optional<uint64_t> statusBarRevision;
        std::optional<bool> capableChat;
        bool operator < (const BuddyDetail&) const { return false; }
    };

    struct BuddyList {
        std::optional<std::string> classification;
        std::optional<std::string> displayName;
        std::optional<uint32_t> totalBuddyCount;
        std::optional<std::vector<Contact>> popularContacts;
        bool operator < (const BuddyList&) const { return false; }
    };

    struct BuddyMessageRequest {
        std::optional<ContentType> contentType;
        std::optional<std::string> text;
        std::optional<Location> location;
        std::optional<std::string> content;
        std::optional<std::map<std::string, std::string>> contentMetadata;
        std::optional<std::string> sourceContentId;
        std::optional<bool> usePermanent;
        std::optional<std::string> toMid;
        bool operator < (const BuddyMessageRequest&) const { return false; }
    };

    struct BuddyNewsEntry {
        std::optional<BuddyBanner> banner;
        std::optional<Contact> contact;
        std::optional<uint64_t> memberCount;
        std::optional<std::string> subtitle;
        std::optional<uint64_t> releasedTime;
        std::optional<uint64_t> newsId;
        bool operator < (const BuddyNewsEntry&) const { return false; }
    };

    struct BuddyNewsView {
        std::optional<bool> hasNext;
        std::optional<std::vector<BuddyNewsEntry>> newsEntries;
        bool operator < (const BuddyNewsView&) const { return false; }
    };

    struct BuddyOnAir {
        std::optional<std::string> mid;
        std::optional<uint64_t> freshnessLifetime;
        std::optional<std::string> onAirId;
        std::optional<bool> onAir;
        std::optional<std::string> text;
        std::optional<uint64_t> viewerCount;
        std::optional<uint64_t> targetCount;
        std::optional<uint64_t> livePlayTime;
        std::optional<std::string> screenAspectRate;
        std::optional<BuddyOnAirType> onAirType;
        std::optional<BuddyOnAirUrls> onAirUrls;
        std::optional<std::string> aspectRatioOfSource;
        std::optional<bool> useFadingOut;
        std::optional<uint64_t> fadingOutIn;
        std::optional<std::string> urlAfterFadingOut;
        std::optional<std::string> labelAfterFadingOut;
        std::optional<bool> useLowerBanner;
        std::optional<std::string> lowerBannerUrl;
        std::optional<std::string> lowerBannerLabel;
        bool operator < (const BuddyOnAir&) const { return false; }
    };

    struct BuddyProfilePopup {
        std::optional<BuddyProfilePopupType> popupType;
        std::optional<std::string> linkUrl;
        std::optional<uint32_t> backgroundColorRgb;
        std::optional<uint32_t> textColorRgb;
        std::optional<std::string> label;
        bool operator < (const BuddyProfilePopup&) const { return false; }
    };

    struct BuddyStatusBar {
        std::optional<std::string> label;
        std::optional<BuddyStatusBarDisplayType> displayType;
        bool operator < (const BuddyStatusBar&) const { return false; }
    };

    struct BuddyTopView {
        std::optional<std::vector<BuddyBanner>> banners;
        std::optional<std::vector<BuddyCollection>> collections;
        std::optional<uint64_t> rotationInterval;
        bool operator < (const BuddyTopView&) const { return false; }
    };

    struct ChannelDomains {
        std::optional<std::vector<ChannelDomain>> channelDomains;
        std::optional<uint64_t> revision;
        bool operator < (const ChannelDomains&) const { return false; }
    };

    struct ChannelInfos {
        std::optional<std::vector<ChannelInfo>> channelInfos;
        std::optional<uint64_t> revision;
        bool operator < (const ChannelInfos&) const { return false; }
    };

    struct ChannelSyncDatas {
        std::optional<std::vector<ChannelInfo>> channelInfos;
        std::optional<std::vector<ChannelDomain>> channelDomains;
        std::optional<uint64_t> revision;
        std::optional<uint64_t> expires;
        bool operator < (const ChannelSyncDatas&) const { return false; }
    };

    struct CoinPayLoad {
        std::optional<uint32_t> payCoin;
        std::optional<uint32_t> freeCoin;
        std::optional<PayloadType> type;
        std::optional<uint32_t> rewardCoin;
        bool operator < (const CoinPayLoad&) const { return false; }
    };

    struct CoinHistory {
        std::optional<uint64_t> payDate;
        std::optional<uint32_t> coinBalance;
        std::optional<uint32_t> coin;
        std::optional<std::string> price;
        std::optional<std::string> title;
        std::optional<bool> refund;
        std::optional<std::string> paySeq;
        std::optional<std::string> currency;
        std::optional<std::string> currencySign;
        std::optional<std::string> displayPrice;
        std::optional<CoinPayLoad> payload;
        std::optional<std::string> channelId;
        bool operator < (const CoinHistory&) const { return false; }
    };

    struct CoinHistoryCondition {
        std::optional<uint64_t> start;
        std::optional<uint32_t> size;
        std::optional<std::string> language;
        std::optional<std::string> eddt;
        std::optional<PaymentType> appStoreCode;
        bool operator < (const CoinHistoryCondition&) const { return false; }
    };

    struct CoinHistoryResult {
        std::optional<std::vector<CoinHistory>> historys;
        std::optional<Coin> balance;
        std::optional<bool> hasNext;
        bool operator < (const CoinHistoryResult&) const { return false; }
    };

    struct CoinPurchaseConfirm {
        std::optional<std::string> orderId;
        std::optional<PaymentType> appStoreCode;
        std::optional<std::string> receipt;
        std::optional<std::string> signature;
        std::optional<std::string> seller;
        std::optional<std::string> requestType;
        std::optional<bool> ignoreReceipt;
        bool operator < (const CoinPurchaseConfirm&) const { return false; }
    };

    struct CoinPurchaseReservation {
        std::optional<std::string> productId;
        std::optional<std::string> country;
        std::optional<std::string> currency;
        std::optional<std::string> price;
        std::optional<PaymentType> appStoreCode;
        std::optional<std::string> language;
        std::optional<PaymentPgType> pgCode;
        std::optional<std::string> redirectUrl;
        bool operator < (const CoinPurchaseReservation&) const { return false; }
    };

    struct CoinUseReservation {
        std::optional<std::string> channelId;
        std::optional<std::string> shopOrderId;
        std::optional<PaymentType> appStoreCode;
        std::optional<std::vector<CoinUseReservationItem>> items;
        std::optional<std::string> country;
        bool operator < (const CoinUseReservation&) const { return false; }
    };

    struct Message {
        std::optional<std::string> from_;
        std::optional<std::string> to;
        std::optional<MIDType> toType;
        std::optional<std::string> id;
        std::optional<uint64_t> createdTime;
        std::optional<uint64_t> deliveredTime;
        std::optional<std::string> text;
        std::optional<Location> location;
        std::optional<bool> hasContent;
        std::optional<ContentType> contentType;
        std::optional<std::string> contentPreview;
        std::optional<std::map<std::string, std::string>> contentMetadata;
        std::optional<uint32_t> sessionId;
        std::optional<std::vector<std::string>> chunks;
        std::optional<std::string> relatedMessageId;
        std::optional<MessageRelationType> messageRelationType;
        std::optional<uint32_t> readCount;
        std::optional<ServiceCode> relatedMessageServiceCode;
        bool operator < (const Message&) const { return false; }
    };

    struct CommitMessageResult {
        std::optional<Message> message;
        std::optional<CommitMessageResultCode> code;
        std::optional<std::string> reason;
        std::optional<uint64_t> successCount;
        std::optional<uint64_t> failCount;
        std::optional<uint64_t> unregisterCount;
        std::optional<uint64_t> blockCount;
        bool operator < (const CommitMessageResult&) const { return false; }
    };

    struct CompactContact {
        std::optional<std::string> mid;
        std::optional<uint64_t> createdTime;
        std::optional<uint64_t> modifiedTime;
        std::optional<ContactStatus> status;
        std::optional<uint64_t> settings;
        std::optional<std::string> displayNameOverridden;
        bool operator < (const CompactContact&) const { return false; }
    };

    struct ContactModification {
        std::optional<ModificationType> type;
        std::optional<std::string> luid;
        std::optional<std::vector<std::string>> phones;
        std::optional<std::vector<std::string>> emails;
        std::optional<std::vector<std::string>> userids;
        bool operator < (const ContactModification&) const { return false; }
    };

    struct ContactRegistration {
        std::optional<Contact> contact;
        std::optional<std::string> luid;
        std::optional<ContactType> contactType;
        std::optional<std::string> contactKey;
        bool operator < (const ContactRegistration&) const { return false; }
    };

    struct ContactReport {
        std::optional<std::string> mid;
        std::optional<bool> exists;
        std::optional<Contact> contact;
        bool operator < (const ContactReport&) const { return false; }
    };

    struct ContactTransition {
        std::optional<std::string> ownerMid;
        std::optional<std::string> targetMid;
        std::optional<ContactStatus> previousStatus;
        std::optional<ContactStatus> resultStatus;
        bool operator < (const ContactTransition&) const { return false; }
    };

    struct DeviceInfo {
        std::optional<std::string> deviceName;
        std::optional<std::string> systemName;
        std::optional<std::string> systemVersion;
        std::optional<std::string> model;
        std::optional<std::string> webViewVersion;
        std::optional<CarrierCode> carrierCode;
        std::optional<std::string> carrierName;
        std::optional<ApplicationType> applicationType;
        bool operator < (const DeviceInfo&) const { return false; }
    };

    struct E2EEGroupSharedKey {
        std::optional<uint32_t> version;
        std::optional<uint32_t> groupKeyId;
        std::optional<std::string> creator;
        std::optional<uint32_t> creatorKeyId;
        std::optional<std::string> receiver;
        std::optional<uint32_t> receiverKeyId;
        std::optional<std::string> encryptedSharedKey;
        std::optional<std::set<ContentType>> allowedTypes;
        bool operator < (const E2EEGroupSharedKey&) const { return false; }
    };

    struct E2EEKeyChain {
        std::optional<std::vector<E2EEKey>> keychain;
        bool operator < (const E2EEKeyChain&) const { return false; }
    };

    struct E2EENegotiationResult {
        std::optional<std::set<ContentType>> allowedTypes;
        std::optional<E2EEPublicKey> publicKey;
        bool operator < (const E2EENegotiationResult&) const { return false; }
    };

    struct EmailConfirmationSession {
        std::optional<EmailConfirmationType> emailConfirmationType;
        std::optional<std::string> verifier;
        std::optional<std::string> targetEmail;
        bool operator < (const EmailConfirmationSession&) const { return false; }
    };

    struct ExtendedProfileBirthday {
        std::optional<std::string> year;
        std::optional<PrivacyLevelType> yearPrivacyLevelType;
        std::optional<bool> yearEnabled;
        std::optional<std::string> day;
        std::optional<PrivacyLevelType> dayPrivacyLevelType;
        std::optional<bool> dayEnabled;
        bool operator < (const ExtendedProfileBirthday&) const { return false; }
    };

    struct ExtendedProfile {
        std::optional<ExtendedProfileBirthday> birthday;
        bool operator < (const ExtendedProfile&) const { return false; }
    };

    struct FriendChannelMatricesResponse {
        std::optional<uint64_t> expires;
        std::optional<std::vector<FriendChannelMatrix>> matrices;
        bool operator < (const FriendChannelMatricesResponse&) const { return false; }
    };

    struct FriendRequest {
        std::optional<std::string> eMid;
        std::optional<std::string> mid;
        std::optional<FriendRequestDirection> direction;
        std::optional<FriendRequestMethod> method;
        std::optional<std::string> param;
        std::optional<uint64_t> timestamp;
        std::optional<uint64_t> seqId;
        std::optional<std::string> displayName;
        std::optional<std::string> picturePath;
        std::optional<std::string> pictureStatus;
        bool operator < (const FriendRequest&) const { return false; }
    };

    struct FriendRequestsInfo {
        std::optional<uint32_t> totalIncomingCount;
        std::optional<uint32_t> totalOutgoingCount;
        std::optional<std::vector<FriendRequest>> recentIncomings;
        std::optional<std::vector<FriendRequest>> recentOutgoings;
        std::optional<uint32_t> totalIncomingLimit;
        std::optional<uint32_t> totalOutgoingLimit;
        bool operator < (const FriendRequestsInfo&) const { return false; }
    };

    struct GetBalanceResponse {
        std::optional<Balance> balance;
        bool operator < (const GetBalanceResponse&) const { return false; }
    };

    struct GetCoinHistoryRequest {
        std::optional<PaymentType> appStoreCode;
        std::optional<std::string> country;
        std::optional<std::string> language;
        std::optional<std::string> searchEndDate;
        std::optional<uint32_t> offset;
        std::optional<uint32_t> limit;
        bool operator < (const GetCoinHistoryRequest&) const { return false; }
    };

    struct GetCoinHistoryResponse {
        std::optional<std::vector<CoinHistory>> histories;
        std::optional<Coin> balance;
        std::optional<uint32_t> offset;
        std::optional<bool> hasNext;
        bool operator < (const GetCoinHistoryResponse&) const { return false; }
    };

    struct GetCoinProductsRequest {
        std::optional<PaymentType> appStoreCode;
        std::optional<std::string> country;
        std::optional<std::string> language;
        std::optional<PaymentPgType> pgCode;
        bool operator < (const GetCoinProductsRequest&) const { return false; }
    };

    struct GetCoinProductsResponse {
        std::optional<std::vector<CoinProductItem>> items;
        bool operator < (const GetCoinProductsResponse&) const { return false; }
    };

    struct GetTotalCoinBalanceRequest {
        std::optional<PaymentType> appStoreCode;
        bool operator < (const GetTotalCoinBalanceRequest&) const { return false; }
    };

    struct Group {
        std::optional<std::string> id;
        std::optional<uint64_t> createdTime;
        std::optional<std::string> name;
        std::optional<std::string> pictureStatus;
        std::optional<bool> preventedJoinByTicket;
        std::optional<GroupPreference> groupPreference;
        std::optional<std::vector<Contact>> members;
        std::optional<Contact> creator;
        std::optional<std::vector<Contact>> invitee;
        std::optional<bool> notificationDisabled;
        std::optional<std::string> picturePath;
        std::optional<std::vector<std::string>> memberMids;
        std::optional<std::vector<std::string>> inviteeMids;
        bool operator < (const Group&) const { return false; }
    };

    struct GroupCall {
        std::optional<bool> online;
        std::optional<std::string> chatMid;
        std::optional<std::string> hostMid;
        std::optional<std::vector<std::string>> memberMids;
        std::optional<uint64_t> started;
        std::optional<GroupCallMediaType> mediaType;
        bool operator < (const GroupCall&) const { return false; }
    };

    struct GroupCallRoute {
        std::optional<std::string> token;
        std::optional<CallHost> cscf;
        std::optional<CallHost> mix;
        bool operator < (const GroupCallRoute&) const { return false; }
    };

    struct IdentityCredential {
        std::optional<IdentityProvider> provider;
        std::optional<std::string> identifier;
        std::optional<std::string> password;
        bool operator < (const IdentityCredential&) const { return false; }
    };

    struct LoginRequest {
        std::optional<LoginType> type;
        std::optional<IdentityProvider> identityProvider;
        std::optional<std::string> identifier;
        std::optional<std::string> password;
        std::optional<bool> keepLoggedIn;
        std::optional<std::string> accessLocation;
        std::optional<std::string> systemName;
        std::optional<std::string> certificate;
        std::optional<std::string> verifier;
        std::optional<std::string> secret;
        std::optional<uint32_t> e2eeVersion;
        bool operator < (const LoginRequest&) const { return false; }
    };

    struct VerificationSessionData {
        std::optional<std::string> sessionId;
        std::optional<VerificationMethod> method;
        std::optional<std::string> callback;
        std::optional<std::string> normalizedPhone;
        std::optional<std::string> countryCode;
        std::optional<std::string> nationalSignificantNumber;
        std::optional<std::vector<VerificationMethod>> availableVerificationMethods;
        std::optional<std::string> callerIdMask;
        bool operator < (const VerificationSessionData&) const { return false; }
    };

    struct LoginResult {
        std::optional<std::string> authToken;
        std::optional<std::string> certificate;
        std::optional<std::string> verifier;
        std::optional<std::string> pinCode;
        std::optional<LoginResultType> type;
        std::optional<uint64_t> lastPrimaryBindTime;
        std::optional<std::string> displayMessage;
        std::optional<VerificationSessionData> sessionForSMSConfirm;
        bool operator < (const LoginResult&) const { return false; }
    };

    struct LoginSession {
        std::optional<std::string> tokenKey;
        std::optional<uint64_t> expirationTime;
        std::optional<ApplicationType> applicationType;
        std::optional<std::string> systemName;
        std::optional<std::string> accessLocation;
        bool operator < (const LoginSession&) const { return false; }
    };

    struct MessageCommitResult {
        std::optional<std::string> requestId;
        std::optional<BuddyResultState> state;
        std::optional<std::string> messageStoreRequestId;
        std::optional<std::vector<std::string>> messageIds;
        std::optional<uint64_t> receiverCount;
        std::optional<uint64_t> successCount;
        std::optional<uint64_t> failCount;
        std::optional<uint64_t> blockCount;
        std::optional<uint64_t> unregisteredCount;
        std::optional<uint64_t> unrelatedCount;
        std::optional<std::string> errorDescription;
        bool operator < (const MessageCommitResult&) const { return false; }
    };

    struct MetaProfile {
        std::optional<uint64_t> createTime;
        std::optional<std::string> regionCode;
        std::optional<std::map<RegistrationType, std::string>> identities;
        std::optional<std::string> udid;
        bool operator < (const MetaProfile&) const { return false; }
    };

    struct MoretabRecommendAccount {
        std::optional<std::string> mid;
        std::optional<std::string> displayName;
        std::optional<std::string> statusMessage;
        std::optional<std::string> pictureStatus;
        std::optional<std::string> picturePath;
        bool operator < (const MoretabRecommendAccount&) const { return false; }
    };

    struct MoretabRecommend {
        std::optional<std::vector<MoretabRecommendAccount>> accounts;
        std::optional<uint64_t> nextUpdateTime;
        std::optional<uint64_t> cacheTtlMillis;
        bool operator < (const MoretabRecommend&) const { return false; }
    };

    struct Profile {
        std::optional<std::string> mid;
        std::optional<std::string> userid;
        std::optional<std::string> phone;
        std::optional<std::string> email;
        std::optional<std::string> regionCode;
        std::optional<std::string> displayName;
        std::optional<std::string> phoneticName;
        std::optional<std::string> pictureStatus;
        std::optional<std::string> thumbnailUrl;
        std::optional<std::string> statusMessage;
        std::optional<bool> allowSearchByUserid;
        std::optional<bool> allowSearchByEmail;
        std::optional<std::string> picturePath;
        std::optional<std::string> musicProfile;
        std::optional<std::string> videoProfile;
        bool operator < (const Profile&) const { return false; }
    };

    struct NearbyEntry {
        std::optional<std::string> emid;
        std::optional<double> distance;
        std::optional<uint32_t> lastUpdatedInSec;
        std::optional<std::map<std::string, std::string>> property;
        std::optional<Profile> profile;
        bool operator < (const NearbyEntry&) const { return false; }
    };

    struct NotiCenterEventData {
        std::optional<std::string> id;
        std::optional<std::string> to;
        std::optional<std::string> from_;
        std::optional<std::string> toChannel;
        std::optional<std::string> fromChannel;
        std::optional<std::string> eventType;
        std::optional<uint64_t> createdTime;
        std::optional<uint64_t> operationRevision;
        std::optional<std::map<std::string, std::string>> content;
        std::optional<std::map<std::string, std::string>> push;
        bool operator < (const NotiCenterEventData&) const { return false; }
    };

    struct NotificationItem {
        std::optional<std::string> id;
        std::optional<std::string> from_;
        std::optional<std::string> to;
        std::optional<std::string> fromChannel;
        std::optional<std::string> toChannel;
        std::optional<uint64_t> revision;
        std::optional<uint64_t> createdTime;
        std::optional<std::map<std::string, std::string>> content;
        bool operator < (const NotificationItem&) const { return false; }
    };

    struct NotificationFetchResult {
        std::optional<NotificationItemFetchMode> fetchMode;
        std::optional<std::vector<NotificationItem>> itemList;
        bool operator < (const NotificationFetchResult&) const { return false; }
    };

    struct Operation {
        std::optional<uint64_t> revision;
        std::optional<uint64_t> createdTime;
        std::optional<OpType> type;
        std::optional<uint32_t> reqSeq;
        std::optional<std::string> checksum;
        std::optional<OpStatus> status;
        std::optional<std::string> param1;
        std::optional<std::string> param2;
        std::optional<std::string> param3;
        std::optional<Message> message;
        bool operator < (const Operation&) const { return false; }
    };

    struct OTPResult {
        std::optional<std::string> otpId;
        std::optional<std::string> otp;
        bool operator < (const OTPResult&) const { return false; }
    };

    struct PaidCallAdCountry {
        std::optional<std::string> countryCode;
        std::optional<std::string> rateDivision;
        bool operator < (const PaidCallAdCountry&) const { return false; }
    };

    struct PaidCallAdResult {
        std::optional<uint32_t> adRemains;
        bool operator < (const PaidCallAdResult&) const { return false; }
    };

    struct PaidCallBalance {
        std::optional<PaidCallProductType> productType;
        std::optional<std::string> productName;
        std::optional<std::string> unit;
        std::optional<uint32_t> limitedPaidBalance;
        std::optional<uint32_t> limitedFreeBalance;
        std::optional<uint32_t> unlimitedPaidBalance;
        std::optional<uint32_t> unlimitedFreeBalance;
        std::optional<uint64_t> startTime;
        std::optional<uint64_t> endTime;
        std::optional<bool> autopayEnabled;
        bool operator < (const PaidCallBalance&) const { return false; }
    };

    struct PaidCallCurrencyExchangeRate {
        std::optional<std::string> currencyCode;
        std::optional<std::string> currencyName;
        std::optional<std::string> currencySign;
        std::optional<bool> preferred;
        std::optional<std::string> coinRate;
        std::optional<std::string> creditRate;
        bool operator < (const PaidCallCurrencyExchangeRate&) const { return false; }
    };

    struct PaidCallDialing {
        std::optional<PaidCallType> type;
        std::optional<std::string> dialedNumber;
        std::optional<std::string> serviceDomain;
        std::optional<PaidCallProductType> productType;
        std::optional<std::string> productName;
        std::optional<bool> multipleProduct;
        std::optional<PaidCallerIdStatus> callerIdStatus;
        std::optional<uint32_t> balance;
        std::optional<std::string> unit;
        std::optional<uint32_t> rate;
        std::optional<std::string> displayCode;
        std::optional<std::string> calledNumber;
        std::optional<std::string> calleeNationalNumber;
        std::optional<std::string> calleeCallingCode;
        std::optional<std::string> rateDivision;
        std::optional<uint32_t> adMaxMin;
        std::optional<uint32_t> adRemains;
        std::optional<std::string> adSessionId;
        bool operator < (const PaidCallDialing&) const { return false; }
    };

    struct PaidCallHistory {
        std::optional<uint64_t> seq;
        std::optional<PaidCallType> type;
        std::optional<std::string> dialedNumber;
        std::optional<std::string> calledNumber;
        std::optional<std::string> toMid;
        std::optional<std::string> toName;
        std::optional<uint64_t> setupTime;
        std::optional<uint64_t> startTime;
        std::optional<uint64_t> endTime;
        std::optional<uint64_t> duration;
        std::optional<uint32_t> terminate;
        std::optional<PaidCallProductType> productType;
        std::optional<uint32_t> charge;
        std::optional<std::string> unit;
        std::optional<std::string> result;
        bool operator < (const PaidCallHistory&) const { return false; }
    };

    struct PaidCallHistoryResult {
        std::optional<std::vector<PaidCallHistory>> historys;
        std::optional<bool> hasNext;
        bool operator < (const PaidCallHistoryResult&) const { return false; }
    };

    struct PaidCallMetadataResult {
        std::optional<std::vector<PaidCallCurrencyExchangeRate>> currencyExchangeRates;
        std::optional<std::vector<std::string>> recommendedCountryCodes;
        std::optional<std::vector<PaidCallAdCountry>> adCountries;
        bool operator < (const PaidCallMetadataResult&) const { return false; }
    };

    struct PaidCallRedeemResult {
        std::optional<std::string> eventName;
        std::optional<uint32_t> eventAmount;
        bool operator < (const PaidCallRedeemResult&) const { return false; }
    };

    struct SpotItem {
        std::optional<std::string> name;
        std::optional<std::string> phone;
        std::optional<SpotCategory> category;
        std::optional<std::string> mid;
        std::optional<std::string> countryAreaCode;
        std::optional<bool> freePhoneCallable;
        bool operator < (const SpotItem&) const { return false; }
    };

    struct PaidCallResponse {
        std::optional<CallHost> host;
        std::optional<PaidCallDialing> dialing;
        std::optional<std::string> token;
        std::optional<std::vector<SpotItem>> spotItems;
        bool operator < (const PaidCallResponse&) const { return false; }
    };

    struct PaidCallUserRate {
        std::optional<std::string> countryCode;
        std::optional<uint32_t> rate;
        std::optional<std::string> rateDivision;
        std::optional<std::string> rateName;
        bool operator < (const PaidCallUserRate&) const { return false; }
    };

    struct PaymentReservation {
        std::optional<std::string> receiverMid;
        std::optional<std::string> productId;
        std::optional<std::string> language;
        std::optional<std::string> location;
        std::optional<std::string> currency;
        std::optional<std::string> price;
        std::optional<PaymentType> appStoreCode;
        std::optional<std::string> messageText;
        std::optional<uint32_t> messageTemplate;
        std::optional<uint64_t> packageId;
        bool operator < (const PaymentReservation&) const { return false; }
    };

    struct PaymentReservationResult {
        std::optional<std::string> orderId;
        std::optional<std::string> confirmUrl;
        std::optional<std::map<std::string, std::string>> extras;
        bool operator < (const PaymentReservationResult&) const { return false; }
    };

    struct PhoneInfoForChannel {
        std::optional<std::string> mid;
        std::optional<std::string> normalizedPhoneNumber;
        std::optional<bool> allowedToSearchByPhoneNumber;
        std::optional<bool> allowedToReceiveMessageFromNonFriend;
        std::optional<std::string> region;
        bool operator < (const PhoneInfoForChannel&) const { return false; }
    };

    struct PhoneVerificationResult {
        std::optional<VerificationResult> verificationResult;
        std::optional<AccountMigrationCheckType> accountMigrationCheckType;
        std::optional<bool> recommendAddFriends;
        bool operator < (const PhoneVerificationResult&) const { return false; }
    };

    struct PlaceSearchInfo {
        std::optional<std::string> name;
        std::optional<std::string> address;
        std::optional<double> latitude;
        std::optional<double> longitude;
        bool operator < (const PlaceSearchInfo&) const { return false; }
    };

    struct PrivateBotMessage {
        std::optional<Message> message;
        std::optional<std::string> linkFrom;
        bool operator < (const PrivateBotMessage&) const { return false; }
    };

    struct ProductCategory {
        std::optional<uint64_t> productCategoryId;
        std::optional<std::string> title;
        std::optional<uint32_t> productCount;
        std::optional<bool> newFlag;
        bool operator < (const ProductCategory&) const { return false; }
    };

    struct Product {
        std::optional<std::string> productId;
        std::optional<uint64_t> packageId;
        std::optional<uint32_t> version;
        std::optional<std::string> authorName;
        std::optional<bool> onSale;
        std::optional<uint32_t> validDays;
        std::optional<uint32_t> saleType;
        std::optional<std::string> copyright;
        std::optional<std::string> title;
        std::optional<std::string> descriptionText;
        std::optional<uint64_t> shopOrderId;
        std::optional<std::string> fromMid;
        std::optional<std::string> toMid;
        std::optional<uint64_t> validUntil;
        std::optional<uint32_t> priceTier;
        std::optional<std::string> price;
        std::optional<std::string> currency;
        std::optional<std::string> currencySymbol;
        std::optional<PaymentType> paymentType;
        std::optional<uint64_t> createDate;
        std::optional<bool> ownFlag;
        std::optional<ProductEventType> eventType;
        std::optional<std::string> urlSchema;
        std::optional<std::string> downloadUrl;
        std::optional<std::string> buddyMid;
        std::optional<uint64_t> publishSince;
        std::optional<bool> newFlag;
        std::optional<bool> missionFlag;
        std::optional<std::vector<ProductCategory>> categories;
        std::optional<std::string> missionButtonText;
        std::optional<std::string> missionShortDescription;
        std::optional<std::string> authorId;
        std::optional<bool> grantedByDefault;
        std::optional<uint32_t> displayOrder;
        std::optional<bool> availableForPresent;
        std::optional<bool> availableForMyself;
        std::optional<bool> hasAnimation;
        std::optional<bool> hasSound;
        std::optional<bool> recommendationsEnabled;
        std::optional<StickerResourceType> stickerResourceType;
        bool operator < (const Product&) const { return false; }
    };

    struct ProductList {
        std::optional<bool> hasNext;
        std::optional<uint64_t> bannerSequence;
        std::optional<ProductBannerLinkType> bannerTargetType;
        std::optional<std::string> bannerTargetPath;
        std::optional<std::vector<Product>> productList;
        std::optional<std::string> bannerLang;
        bool operator < (const ProductList&) const { return false; }
    };

    struct ProductSimpleList {
        std::optional<bool> hasNext;
        std::optional<uint32_t> reinvokeHour;
        std::optional<uint64_t> lastVersionSeq;
        std::optional<std::vector<ProductSimple>> productList;
        std::optional<uint64_t> recentNewReleaseDate;
        std::optional<uint64_t> recentEventReleaseDate;
        bool operator < (const ProductSimpleList&) const { return false; }
    };

    struct ProximityMatchCandidateEntry {
        std::optional<Contact> contact;
        std::optional<BuddyDetail> buddyDetail;
        bool operator < (const ProximityMatchCandidateEntry&) const { return false; }
    };

    struct ProximityMatchCandidateResult {
        std::optional<std::vector<ProximityMatchCandidateEntry>> users;
        std::optional<std::vector<ProximityMatchCandidateEntry>> buddies;
        std::optional<bool> endOfResult;
        bool operator < (const ProximityMatchCandidateResult&) const { return false; }
    };

    struct PublicKey {
        std::optional<AsymmetricKeyAlgorithm> keyAlgorithm;
        std::optional<uint32_t> keySize;
        std::optional<std::string> keyData;
        std::optional<uint64_t> createdTime;
        bool operator < (const PublicKey&) const { return false; }
    };

    struct PublicKeychain {
        std::optional<std::set<PublicKey>> publicKeys;
        bool operator < (const PublicKeychain&) const { return false; }
    };

    struct QueueingPolicy {
        std::optional<uint32_t> priority;
        std::optional<std::string> policy;
        bool operator < (const QueueingPolicy&) const { return false; }
    };

    struct RegisterWithPhoneNumberResult {
        std::optional<std::string> authToken;
        std::optional<bool> recommendEmailRegistration;
        std::optional<std::string> certificate;
        bool operator < (const RegisterWithPhoneNumberResult&) const { return false; }
    };

    struct RegisterWithSnsIdResult {
        std::optional<std::string> authToken;
        std::optional<bool> userCreated;
        std::optional<bool> recommendEmailRegistration;
        bool operator < (const RegisterWithSnsIdResult&) const { return false; }
    };

    struct RequestTokenResponse {
        std::optional<std::string> requestToken;
        std::optional<std::string> returnUrl;
        bool operator < (const RequestTokenResponse&) const { return false; }
    };

    struct RingbackTone {
        std::optional<std::string> uuid;
        std::optional<std::string> trackId;
        std::optional<std::string> title;
        std::optional<std::string> oid;
        std::optional<std::map<std::string, std::string>> tids;
        bool operator < (const RingbackTone&) const { return false; }
    };

    struct Room {
        std::optional<std::string> mid;
        std::optional<uint64_t> createdTime;
        std::optional<std::vector<Contact>> contacts;
        std::optional<bool> notificationDisabled;
        std::optional<std::vector<std::string>> memberMids;
        bool operator < (const Room&) const { return false; }
    };

    struct RSAKey {
        std::optional<std::string> keynm;
        std::optional<std::string> nvalue;
        std::optional<std::string> evalue;
        std::optional<std::string> sessionKey;
        bool operator < (const RSAKey&) const { return false; }
    };

    struct SecurityCenterResult {
        std::optional<std::string> uri;
        std::optional<std::string> token;
        std::optional<std::string> cookiePath;
        std::optional<bool> skip;
        bool operator < (const SecurityCenterResult&) const { return false; }
    };

    struct SendBuddyMessageResult {
        std::optional<std::string> requestId;
        std::optional<BuddyResultState> state;
        std::optional<std::string> messageId;
        std::optional<uint32_t> eventNo;
        std::optional<uint64_t> receiverCount;
        std::optional<uint64_t> successCount;
        std::optional<uint64_t> failCount;
        std::optional<uint64_t> cancelCount;
        std::optional<uint64_t> blockCount;
        std::optional<uint64_t> unregisterCount;
        std::optional<uint64_t> unrelatedCount;
        std::optional<uint64_t> timestamp;
        std::optional<std::string> message;
        bool operator < (const SendBuddyMessageResult&) const { return false; }
    };

    struct SendPostbackRequest {
        std::optional<std::string> messageId;
        std::optional<std::string> url;
        std::optional<std::string> chatMID;
        std::optional<std::string> originMID;
        bool operator < (const SendPostbackRequest&) const { return false; }
    };

    struct SetBuddyOnAirResult {
        std::optional<std::string> requestId;
        std::optional<BuddyResultState> state;
        std::optional<uint32_t> eventNo;
        std::optional<uint64_t> receiverCount;
        std::optional<uint64_t> successCount;
        std::optional<uint64_t> failCount;
        std::optional<uint64_t> cancelCount;
        std::optional<uint64_t> unregisterCount;
        std::optional<uint64_t> timestamp;
        std::optional<std::string> message;
        bool operator < (const SetBuddyOnAirResult&) const { return false; }
    };

    struct Settings {
        std::optional<bool> notificationEnable;
        std::optional<uint64_t> notificationMuteExpiration;
        std::optional<bool> notificationNewMessage;
        std::optional<bool> notificationGroupInvitation;
        std::optional<bool> notificationShowMessage;
        std::optional<bool> notificationIncomingCall;
        std::optional<std::string> notificationSoundMessage;
        std::optional<std::string> notificationSoundGroup;
        std::optional<bool> notificationDisabledWithSub;
        std::optional<bool> notificationPayment;
        std::optional<bool> privacySyncContacts;
        std::optional<bool> privacySearchByPhoneNumber;
        std::optional<bool> privacySearchByUserid;
        std::optional<bool> privacySearchByEmail;
        std::optional<bool> privacyAllowSecondaryDeviceLogin;
        std::optional<bool> privacyProfileImagePostToMyhome;
        std::optional<bool> privacyReceiveMessagesFromNotFriend;
        std::optional<bool> privacyAgreeUseLineCoinToPaidCall;
        std::optional<bool> privacyAgreeUsePaidCall;
        std::optional<bool> privacyAllowFriendRequest;
        std::optional<std::string> contactMyTicket;
        std::optional<IdentityProvider> identityProvider;
        std::optional<std::string> identityIdentifier;
        std::optional<std::map<SnsIdType, std::string>> snsAccounts;
        std::optional<bool> phoneRegistration;
        std::optional<EmailConfirmationStatus> emailConfirmationStatus;
        std::optional<AccountMigrationPincodeType> accountMigrationPincodeType;
        std::optional<bool> enforcedInputAccountMigrationPincode;
        std::optional<SecurityCenterSettingsType> securityCenterSettingsType;
        std::optional<bool> allowUnregistrationSecondaryDevice;
        std::optional<std::string> preferenceLocale;
        std::optional<std::map<CustomMode, std::string>> customModes;
        std::optional<bool> e2eeEnable;
        std::optional<bool> hitokotoBackupRequested;
        std::optional<bool> privacyProfileMusicPostToMyhome;
        std::optional<bool> privacyAllowNearby;
        std::optional<uint64_t> agreementNearbyTime;
        std::optional<uint64_t> agreementSquareTime;
        std::optional<bool> notificationMention;
        std::optional<uint64_t> botUseAgreementAcceptedAt;
        bool operator < (const Settings&) const { return false; }
    };

    struct ShopUpdates {
        std::optional<uint64_t> latestNewReleaseTime;
        std::optional<uint64_t> latestEventReleaseTime;
        std::optional<uint64_t> latestCategoryUpdateTime;
        std::optional<uint64_t> lastVersion;
        std::optional<std::vector<ProductSimple>> updatedProductList;
        bool operator < (const ShopUpdates&) const { return false; }
    };

    struct SyncParamMid {
        std::optional<std::string> mid;
        std::optional<Diff> diff;
        std::optional<uint64_t> revision;
        bool operator < (const SyncParamMid&) const { return false; }
    };

    struct SyncParamContact {
        std::optional<SyncParamMid> syncParamMid;
        std::optional<ContactStatus> contactStatus;
        bool operator < (const SyncParamContact&) const { return false; }
    };

    struct SyncRelations {
        std::optional<bool> syncAll;
        std::optional<std::vector<SyncParamContact>> syncParamContact;
        std::optional<std::vector<SyncParamMid>> syncParamMid;
        bool operator < (const SyncRelations&) const { return false; }
    };

    struct SyncScope {
        std::optional<bool> syncProfile;
        std::optional<bool> syncSettings;
        std::optional<bool> syncSticker;
        std::optional<bool> syncThemeShop;
        std::optional<SyncRelations> contact;
        std::optional<SyncRelations> group;
        std::optional<SyncRelations> room;
        std::optional<SyncRelations> chat;
        bool operator < (const SyncScope&) const { return false; }
    };

    struct SIMInfo {
        std::optional<std::string> phoneNumber;
        std::optional<std::string> countryCode;
        bool operator < (const SIMInfo&) const { return false; }
    };

    struct SimpleChannelClient {
        std::optional<std::string> applicationType;
        std::optional<std::string> applicationVersion;
        std::optional<std::string> locale;
        std::optional<std::string> mid;
        bool operator < (const SimpleChannelClient&) const { return false; }
    };

    struct SimpleChannelContact {
        std::optional<std::string> mid;
        std::optional<std::string> displayName;
        std::optional<std::string> pictureStatus;
        std::optional<std::string> picturePath;
        std::optional<std::string> statusMessage;
        std::optional<std::string> userid;
        std::optional<std::string> regionCode;
        bool operator < (const SimpleChannelContact&) const { return false; }
    };

    struct SnsFriend {
        std::optional<std::string> snsUserId;
        std::optional<std::string> snsUserName;
        std::optional<SnsIdType> snsIdType;
        bool operator < (const SnsFriend&) const { return false; }
    };

    struct SnsFriendContactRegistration {
        std::optional<Contact> contact;
        std::optional<SnsIdType> snsIdType;
        std::optional<std::string> snsUserId;
        bool operator < (const SnsFriendContactRegistration&) const { return false; }
    };

    struct SnsFriendModification {
        std::optional<ModificationType> type;
        std::optional<SnsFriend> snsFriend;
        bool operator < (const SnsFriendModification&) const { return false; }
    };

    struct SnsFriends {
        std::optional<std::vector<SnsFriend>> snsFriends;
        std::optional<bool> hasMore;
        bool operator < (const SnsFriends&) const { return false; }
    };

    struct SnsIdUserStatus {
        std::optional<bool> userExisting;
        std::optional<bool> phoneNumberRegistered;
        std::optional<bool> sameDevice;
        std::optional<AccountMigrationCheckType> accountMigrationCheckType;
        bool operator < (const SnsIdUserStatus&) const { return false; }
    };

    struct SnsProfile {
        std::optional<std::string> snsUserId;
        std::optional<std::string> snsUserName;
        std::optional<std::string> email;
        std::optional<std::string> thumbnailUrl;
        bool operator < (const SnsProfile&) const { return false; }
    };

    struct SpotNearbyItem {
        std::optional<SpotItem> spotItem;
        std::optional<Location> location;
        bool operator < (const SpotNearbyItem&) const { return false; }
    };

    struct SpotNearbyResponse {
        std::optional<std::vector<SpotNearbyItem>> spotNearbyItems;
        bool operator < (const SpotNearbyResponse&) const { return false; }
    };

    struct SpotPhoneNumberResponse {
        std::optional<std::vector<SpotItem>> spotItems;
        bool operator < (const SpotPhoneNumberResponse&) const { return false; }
    };

    struct SuggestDictionary {
        std::optional<std::string> language;
        std::optional<std::string> name;
        bool operator < (const SuggestDictionary&) const { return false; }
    };

    struct SuggestItemDictionaryIncrement {
        std::optional<SuggestDictionaryIncrementStatus> status;
        std::optional<uint64_t> revision;
        std::optional<std::string> scheme;
        std::optional<std::string> data;
        bool operator < (const SuggestItemDictionaryIncrement&) const { return false; }
    };

    struct SuggestTagDictionaryIncrement {
        std::optional<SuggestDictionaryIncrementStatus> status;
        std::optional<std::string> language;
        std::optional<uint64_t> revision;
        std::optional<std::string> scheme;
        std::optional<std::string> data;
        bool operator < (const SuggestTagDictionaryIncrement&) const { return false; }
    };

    struct SuggestDictionaryIncrements {
        std::optional<SuggestItemDictionaryIncrement> itemIncrement;
        std::optional<std::vector<SuggestTagDictionaryIncrement>> tagIncrements;
        bool operator < (const SuggestDictionaryIncrements&) const { return false; }
    };

    struct SuggestItemDictionaryRevision {
        std::optional<uint64_t> revision;
        std::optional<std::string> scheme;
        bool operator < (const SuggestItemDictionaryRevision&) const { return false; }
    };

    struct SuggestTagDictionaryRevision {
        std::optional<std::string> language;
        std::optional<uint64_t> revision;
        std::optional<std::string> scheme;
        bool operator < (const SuggestTagDictionaryRevision&) const { return false; }
    };

    struct SuggestDictionaryRevisions {
        std::optional<SuggestItemDictionaryRevision> itemRevision;
        std::optional<std::vector<SuggestTagDictionaryRevision>> tagRevisions;
        bool operator < (const SuggestDictionaryRevisions&) const { return false; }
    };

    struct SuggestDictionarySettings {
        std::optional<uint64_t> revision;
        std::optional<uint64_t> newRevision;
        std::optional<std::vector<SuggestDictionary>> dictionaries;
        std::optional<std::vector<std::string>> preloadedDictionaries;
        bool operator < (const SuggestDictionarySettings&) const { return false; }
    };

    struct SystemConfiguration {
        std::optional<std::string> endpoint;
        std::optional<std::string> endpointSsl;
        std::optional<std::string> updateUrl;
        std::optional<std::string> c2dmAccount;
        std::optional<std::string> nniServer;
        bool operator < (const SystemConfiguration&) const { return false; }
    };

    struct Ticket {
        std::optional<std::string> id;
        std::optional<uint64_t> expirationTime;
        std::optional<uint32_t> maxUseCount;
        bool operator < (const Ticket&) const { return false; }
    };

    struct TMessageBox {
        std::optional<std::string> id;
        std::optional<std::string> channelId;
        std::optional<uint64_t> lastSeq;
        std::optional<uint64_t> unreadCount;
        std::optional<uint64_t> lastModifiedTime;
        std::optional<uint32_t> status;
        std::optional<MIDType> midType;
        std::optional<std::vector<Message>> lastMessages;
        bool operator < (const TMessageBox&) const { return false; }
    };

    struct TMessageBoxWrapUp {
        std::optional<TMessageBox> messageBox;
        std::optional<std::string> name;
        std::optional<std::vector<Contact>> contacts;
        std::optional<std::string> pictureRevision;
        bool operator < (const TMessageBoxWrapUp&) const { return false; }
    };

    struct TMessageBoxWrapUpResponse {
        std::optional<std::vector<TMessageBoxWrapUp>> messageBoxWrapUpList;
        std::optional<uint32_t> totalSize;
        bool operator < (const TMessageBoxWrapUpResponse&) const { return false; }
    };

    struct TMessageReadRangeEntry {
        std::optional<uint64_t> startMessageId;
        std::optional<uint64_t> endMessageId;
        std::optional<uint64_t> startTime;
        std::optional<uint64_t> endTime;
        bool operator < (const TMessageReadRangeEntry&) const { return false; }
    };

    struct TMessageReadRange {
        std::optional<std::string> chatId;
        std::optional<std::map<std::string, std::vector<TMessageReadRangeEntry>>> ranges;
        bool operator < (const TMessageReadRange&) const { return false; }
    };

    struct UnregisterBuddyResult {
        std::optional<std::string> requestId;
        std::optional<BuddyResultState> state;
        std::optional<uint32_t> eventNo;
        std::optional<std::string> message;
        std::optional<uint64_t> timestamp;
        std::optional<uint64_t> subscriberCountToRemove;
        std::optional<uint64_t> subscriberCountRemoved;
        bool operator < (const UnregisterBuddyResult&) const { return false; }
    };

    struct UpdateBuddyProfileResult {
        std::optional<std::string> requestId;
        std::optional<BuddyResultState> state;
        std::optional<uint32_t> eventNo;
        std::optional<uint64_t> receiverCount;
        std::optional<uint64_t> successCount;
        std::optional<uint64_t> failCount;
        std::optional<uint64_t> cancelCount;
        std::optional<uint64_t> unregisterCount;
        std::optional<uint64_t> timestamp;
        std::optional<std::string> message;
        std::optional<std::string> urlhash;
        bool operator < (const UpdateBuddyProfileResult&) const { return false; }
    };

    struct AgeCheckDocomoResult {
        std::optional<std::string> authUrl;
        std::optional<UserAgeType> userAgeType;
        bool operator < (const AgeCheckDocomoResult&) const { return false; }
    };

    struct AgeCheckRequestResult {
        std::optional<std::string> authUrl;
        std::optional<std::string> sessionId;
        bool operator < (const AgeCheckRequestResult&) const { return false; }
    };

    struct AnalyticsInfo {
        std::optional<double> gaSamplingRate;
        std::optional<std::string> tmid;
        bool operator < (const AnalyticsInfo&) const { return false; }
    };

    struct UserAuthStatus {
        std::optional<bool> phoneNumberRegistered;
        std::optional<std::vector<SnsIdType>> registeredSnsIdTypes;
        std::optional<AccountMigrationCheckType> accountMigrationCheckType;
        bool operator < (const UserAuthStatus&) const { return false; }
    };

    struct UserTicketResponse {
        std::optional<std::string> mid;
        std::optional<std::string> userTicket;
        bool operator < (const UserTicketResponse&) const { return false; }
    };

    struct ValidateContactsResult {
        std::optional<uint64_t> receiverCount;
        std::optional<uint64_t> successCount;
        std::optional<uint64_t> blockCount;
        std::optional<uint64_t> unregisterCount;
        std::optional<uint64_t> unrelatedCount;
        std::optional<uint64_t> failCount;
        bool operator < (const ValidateContactsResult&) const { return false; }
    };

    struct WapInvitation {
        std::optional<WapInvitationType> type;
        std::optional<std::string> inviteeEmail;
        std::optional<std::string> inviterMid;
        std::optional<std::string> roomMid;
        bool operator < (const WapInvitation&) const { return false; }
    };

    // exception struct
    struct ChannelException {
        std::optional<ChannelErrorCode> code;
        std::optional<std::string> reason;
        std::optional<std::map<std::string, std::string>> parameterMap;
    };

    // exception struct
    struct PointException {
        std::optional<PointErrorCode> code;
        std::optional<std::string> reason;
        std::optional<std::map<std::string, std::string>> extra;
    };

    // exception struct
    struct ShouldSyncException {
        std::optional<uint64_t> syncOpRevision;
        std::optional<SyncScope> syncScope;
        std::optional<SyncTriggerReason> syncReason;
        std::optional<std::string> message;
    };

    // exception struct
    struct TalkException {
        std::optional<ErrorCode> code;
        std::optional<std::string> reason;
        std::optional<std::map<std::string, std::string>> parameterMap;
    };

    namespace read {

        namespace request {

            void getMoretabRecommend(char const*& _buffer);

            void requestBanPageForUser(char const*& _buffer);

            void requestBanPage(char const*& _buffer);

            void reserveCoinPurchase(char const*& _buffer, CoinPurchaseReservation& request);

            void getProductCategories(char const*& _buffer, std::string& language, std::string& country);

            void getProductList(char const*& _buffer, std::vector<std::string>& productIdList, std::string& language, std::string& country);

            void getCoinPurchaseHistory(char const*& _buffer, CoinHistoryCondition& request);

            void buyFreeProduct(char const*& _buffer, std::string& receiverMid, std::string& productId, uint32_t& messageTemplate, std::string& language, std::string& country, uint64_t& packageId);

            void getProductListWithCarrier(char const*& _buffer, std::vector<std::string>& productIdList, std::string& language, std::string& country, std::string& carrierCode);

            void getDefaultProducts(char const*& _buffer, std::string& language, std::string& country, std::string& carrierCode);

            void getProductsForCategory(char const*& _buffer, uint64_t& start, uint32_t& size, std::string& language, std::string& country, uint64_t& category);

            void notifyDownloaded(char const*& _buffer, uint64_t& packageId, std::string& language);

            void getFreePackagesWithoutEvent(char const*& _buffer, uint64_t& start, uint32_t& size, std::string& language, std::string& country);

            void getProduct(char const*& _buffer, uint64_t& packageID, std::string& language, std::string& country);

            void getEventPackages(char const*& _buffer, uint64_t& start, uint32_t& size, std::string& language, std::string& country);

            void getActivePurchaseVersions(char const*& _buffer, uint64_t& start, uint32_t& size, std::string& language, std::string& country);

            void getCoinProductsByPgCode(char const*& _buffer, PaymentType& appStoreCode, PaymentPgType& pgCode, std::string& country, std::string& language);

            void getNewlyReleasedPackages(char const*& _buffer, uint64_t& start, uint32_t& size, std::string& language, std::string& country);

            void getDownloads(char const*& _buffer, uint64_t& start, uint32_t& size, std::string& language, std::string& country);

            void getCoinProducts(char const*& _buffer, PaymentType& appStoreCode, std::string& country, std::string& language);

            void searchProducts(char const*& _buffer, uint64_t& start, uint32_t& size, std::string& language, std::string& country, std::string& query);

            void buyMustbuyProduct(char const*& _buffer, std::string& receiverMid, std::string& productId, uint32_t& messageTemplate, std::string& language, std::string& country, uint64_t& packageId, std::string& serialNumber);

            void getRecommendationsForProduct(char const*& _buffer, uint64_t& packageID, uint32_t& offset, uint32_t& limit, std::string& language, std::string& country);

            void getUpdates(char const*& _buffer, std::string& language, std::string& country, uint64_t& localVersion);

            void getActivePurchases(char const*& _buffer, uint64_t& start, uint32_t& size, std::string& language, std::string& country);

            void getProductWithCarrier(char const*& _buffer, uint64_t& packageID, std::string& language, std::string& country, std::string& carrierCode);

            void buyCoinProduct(char const*& _buffer, PaymentReservation& paymentReservation);

            void getPopularPackages(char const*& _buffer, uint64_t& start, uint32_t& size, std::string& language, std::string& country);

            void reservePayment(char const*& _buffer, PaymentReservation& paymentReservation);

            void getPresentsSent(char const*& _buffer, uint64_t& start, uint32_t& size, std::string& language, std::string& country);

            void checkCanReceivePresent(char const*& _buffer, std::string& recipientMid, uint64_t& packageId, std::string& language, std::string& country);

            void getFreePackages(char const*& _buffer, uint64_t& start, uint32_t& size, std::string& language, std::string& country);

            void getPurchaseHistory(char const*& _buffer, uint64_t& start, uint32_t& size, std::string& language, std::string& country);

            void getTotalBalance(char const*& _buffer, PaymentType& appStoreCode);

            void getCoinUseAndRefundHistory(char const*& _buffer, CoinHistoryCondition& request);

            void getPresentsReceived(char const*& _buffer, uint64_t& start, uint32_t& size, std::string& language, std::string& country);

            void getPlaceSearchInfo(char const*& _buffer, PlaceSearchProvider& provider, std::string& keyword, std::string& clientLocale, double& latitude, double& longitude, uint32_t& radius);

            void getUserStatus(char const*& _buffer, std::string& mid);

            void updateProfileAttributeForChannel(char const*& _buffer, ProfileAttribute& profileAttribute, std::string& value);

            void getAllSimpleChannelContacts(char const*& _buffer, bool& statusSticonFallbackDisabled);

            void getUserIdentities(char const*& _buffer);

            void markPaidCallAd(char const*& _buffer, std::string& dialedNumber, std::string& language, bool& disableCallerId);

            void isGroupMember(char const*& _buffer, std::string& groupId);

            void getPhoneInfoFromPhoneNumber(char const*& _buffer, std::string& region, std::string& phoneNumber);

            void redeemPaidCallVoucher(char const*& _buffer, std::string& serial, std::string& language);

            void getPreferredDisplayName(char const*& _buffer, std::vector<std::string>& mids);

            void getContactsForChannel(char const*& _buffer, std::vector<std::string>& ids);

            void getCallCreditProducts(char const*& _buffer, PaymentType& appStoreCode, PaymentPgType& pgCode, std::string& country, std::string& language);

            void getCompactContacts(char const*& _buffer, uint64_t& lastModifiedTimestamp);

            void notifyNotiCenterEvent(char const*& _buffer, NotiCenterEventData& event);

            void isInContact(char const*& _buffer, std::string& mid);

            void lookupGroupMembers(char const*& _buffer, std::string& groupId, std::vector<std::string>& mids);

            void getRoomInformation(char const*& _buffer, std::string& roomMid);

            void getGroupCall(char const*& _buffer, std::string& chatMid);

            void isAllowSecondaryDeviceLogin(char const*& _buffer);

            void getPrimaryClientForChannel(char const*& _buffer);

            void createRoomWithBuddy(char const*& _buffer, uint32_t& reqSeq, std::string& buddyMid, std::vector<std::string>& contactIds);

            void getDisplayName(char const*& _buffer, std::string& mid);

            void getPaidCallMetadata(char const*& _buffer, std::string& language);

            void getMid(char const*& _buffer);

            void getUserCountryForBilling(char const*& _buffer, std::string& country, std::string& remoteIp);

            void getFavoriteGroupIdsForChannel(char const*& _buffer);

            void getPaidCallHistory(char const*& _buffer, uint64_t& start, uint32_t& size, std::string& language);

            void sendPinCodeOperation(char const*& _buffer, std::string& verifier);

            void inviteIntoGroupCall(char const*& _buffer, std::string& chatMid, std::vector<std::string>& memberMids, GroupCallMediaType& mediaType);

            void getFriendMids(char const*& _buffer);

            void getMetaProfile(char const*& _buffer);

            void sendMessageForChannel(char const*& _buffer, Message& message);

            void activeBuddySubscriberCount(char const*& _buffer);

            void getCallCreditPurchaseHistory(char const*& _buffer, CoinHistoryCondition& request);

            void isRoomMember(char const*& _buffer, std::string& roomId);

            void sendSystemOAMessage(char const*& _buffer, Message& message);

            void acquirePaidCallRoute(char const*& _buffer, PaidCallType& paidCallType, std::string& dialedNumber, std::string& language, std::string& networkCode, bool& disableCallerId, std::string& referer, std::string& adSessionId);

            void getGroupsForChannel(char const*& _buffer, std::vector<std::string>& groupIds);

            void getUserCreateTime(char const*& _buffer);

            void registerChannelCP(char const*& _buffer, std::string& cpId, std::string& registerPassword);

            void reserveCallCreditPurchase(char const*& _buffer, CoinPurchaseReservation& request);

            void acquirePaidCallCurrencyExchangeRate(char const*& _buffer, std::string& language);

            void getRoomMemberMidsForAppPlatform(char const*& _buffer, std::string& roomId);

            void getPaidCallBalanceList(char const*& _buffer, std::string& language);

            void getPersonalInfos(char const*& _buffer, std::set<PersonalInfo>& requiredPersonalInfos);

            void getPrimaryClientsForChannel(char const*& _buffer, std::vector<std::string>& userMids);

            void addBuddyToContact(char const*& _buffer, std::string& buddyMid);

            void getGroupMemberMidsForAppPlatform(char const*& _buffer, std::string& groupId);

            void getUserLanguage(char const*& _buffer);

            void lookupPaidCall(char const*& _buffer, std::string& dialedNumber, std::string& language, std::string& referer);

            void getReverseCompactContacts(char const*& _buffer, std::vector<std::string>& ids);

            void getPaidCallAdStatus(char const*& _buffer);

            void findContactByUseridWithoutAbuseBlockForChannel(char const*& _buffer, std::string& userid);

            void getGroupMemberMids(char const*& _buffer, std::string& groupId);

            void sendMessageWithoutRelationship(char const*& _buffer, Message& message);

            void displayBuddySubscriberCountInBulk(char const*& _buffer, std::vector<std::string>& mids);

            void lookupRoomMembers(char const*& _buffer, std::string& roomId, std::vector<std::string>& mids);

            void getFavoriteMidsForChannel(char const*& _buffer);

            void getAllContactIdsForChannel(char const*& _buffer);

            void displayBuddySubscriberCount(char const*& _buffer);

            void getProfileForChannel(char const*& _buffer);

            void getUserTickets(char const*& _buffer, std::vector<std::string>& userMids);

            void getOAFriendMids(char const*& _buffer);

            void searchPaidCallUserRate(char const*& _buffer, std::string& countryCode, std::string& language);

            void getJoinedGroupIdsForChannel(char const*& _buffer);

            void acquireGroupCallRoute(char const*& _buffer, std::string& chatMid, GroupCallMediaType& mediaType);

            void getUserMidsWhoAddedMe(char const*& _buffer);

            void getIdentityCredential(char const*& _buffer);

            void addOperationForChannel(char const*& _buffer, OpType& opType, std::string& param1, std::string& param2, std::string& param3);

            void getSimpleChannelContacts(char const*& _buffer, std::vector<std::string>& ids, bool& statusSticonFallbackDisabled);

            void getUserLastSentMessageTimeStamp(char const*& _buffer, std::string& mid);

            void registerVirtualAccount(char const*& _buffer, std::string& locale, std::string& encryptedVirtualUserId, std::string& encryptedPassword);

            void unregisterVirtualAccount(char const*& _buffer, std::string& virtualMid);

            void requestVirtualAccountPasswordChange(char const*& _buffer, std::string& virtualMid, std::string& encryptedVirtualUserId, std::string& encryptedOldPassword, std::string& encryptedNewPassword);

            void notifyEmailConfirmationResult(char const*& _buffer, std::map<std::string, std::string>& parameterMap);

            void requestVirtualAccountPasswordSet(char const*& _buffer, std::string& virtualMid, std::string& encryptedVirtualUserId, std::string& encryptedNewPassword);

            void getRSAKey(char const*& _buffer);

            void queryBeaconActions(char const*& _buffer, std::string& hwid, std::string& secureMessage, ApplicationType& applicationType, std::string& applicationVersion, std::string& lang);

            void notifyBeaconDetected(char const*& _buffer, std::string& hwid, std::string& secureMessage, BeaconNotificationType& notificationType);

            void getDomains(char const*& _buffer, uint64_t& lastSynced);

            void approveChannelAndIssueRequestToken(char const*& _buffer, std::string& channelId, std::string& otpId);

            void issueOTP(char const*& _buffer, std::string& channelId);

            void getChannelSettings(char const*& _buffer);

            void getChannelNotificationSettings(char const*& _buffer, std::string& locale);

            void updateChannelNotificationSetting(char const*& _buffer, std::vector<ChannelNotificationSetting>& setting);

            void updateChannelSettings(char const*& _buffer, ChannelSettings& channelSettings);

            void getCommonDomains(char const*& _buffer, uint64_t& lastSynced);

            void issueRequestTokenWithAuthScheme(char const*& _buffer, std::string& channelId, std::string& otpId, std::vector<std::string>& authScheme, std::string& returnUrl);

            void getChannelNotificationSetting(char const*& _buffer, std::string& channelId, std::string& locale);

            void issueChannelToken(char const*& _buffer, std::string& channelId);

            void getChannels(char const*& _buffer, uint64_t& lastSynced, std::string& locale);

            void fetchNotificationItems(char const*& _buffer, uint64_t& localRev);

            void getChannelInfo(char const*& _buffer, std::string& channelId, std::string& locale);

            void getNotificationBadgeCount(char const*& _buffer, uint64_t& localRev);

            void issueRequestToken(char const*& _buffer, std::string& channelId, std::string& otpId);

            void revokeChannel(char const*& _buffer, std::string& channelId);

            void getApprovedChannels(char const*& _buffer, uint64_t& lastSynced, std::string& locale);

            void getFriendChannelMatrices(char const*& _buffer, std::vector<std::string>& channelIds);

            void issueRequestTokenForAutoLogin(char const*& _buffer, std::string& channelId, std::string& otpId, std::string& redirectUrl);

            void getUpdatedChannelIds(char const*& _buffer, std::vector<ChannelIdWithLastUpdated>& channelIds);

            void reserveCoinUse(char const*& _buffer, CoinUseReservation& request, std::string& locale);

            void syncChannelData(char const*& _buffer, uint64_t& lastSynced, std::string& locale);

            void approveChannelAndIssueChannelToken(char const*& _buffer, std::string& channelId);

            void getSnsFriends(char const*& _buffer, SnsIdType& snsIdType, std::string& snsAccessToken, uint32_t& startIdx, uint32_t& limit);

            void getSnsMyProfile(char const*& _buffer, SnsIdType& snsIdType, std::string& snsAccessToken);

            void postSnsInvitationMessage(char const*& _buffer, SnsIdType& snsIdType, std::string& snsAccessToken, std::string& toSnsUserId);

            void reportDeviceState(char const*& _buffer, std::map<DeviceBooleanStateKey, bool>& booleanState, std::map<DeviceStringStateKey, std::string>& stringState);

            void notifySleepV2(char const*& _buffer, std::map<ServiceCode, ClientLastStatus>& lastStatusMap);

            void updateNotificationToken(char const*& _buffer, std::string& token, NotificationType& type);

            void updateGroup(char const*& _buffer, uint32_t& reqSeq, Group& group);

            void verifyAccountMigrationPincode(char const*& _buffer, std::string& migrationPincodeSessionId, std::string& accountMigrationPincode);

            void registerWithExistingSnsIdAndIdentityCredential(char const*& _buffer, IdentityCredential& identityCredential, std::string& region, std::string& udidHash, DeviceInfo& deviceInfo, std::string& migrationPincodeSessionId);

            void registerDeviceWithoutPhoneNumber(char const*& _buffer, std::string& region, std::string& udidHash, DeviceInfo& deviceInfo);

            void changeVerificationMethod(char const*& _buffer, std::string& sessionId, VerificationMethod& method);

            void setBuddyLocation(char const*& _buffer, std::string& mid, uint32_t& index, Geolocation& location);

            void getFriendRequests(char const*& _buffer, FriendRequestDirection& direction, uint64_t& lastSeenSeqId);

            void kickoutFromGroup(char const*& _buffer, uint32_t& reqSeq, std::string& groupId, std::vector<std::string>& contactIds);

            void verifyIdentityCredentialWithResult(char const*& _buffer, IdentityCredential& identityCredential, std::string& migrationPincodeSessionId);

            void sendEchoPush(char const*& _buffer, std::string& text);

            void createSession(char const*& _buffer);

            void reissueDeviceCredential(char const*& _buffer);

            void getRecommendationIds(char const*& _buffer);

            void inviteViaEmail(char const*& _buffer, uint32_t& reqSeq, std::string& email, std::string& name);

            void getRoomsV2(char const*& _buffer, std::vector<std::string>& roomIds);

            void getReadMessageOps(char const*& _buffer, std::string& chatId);

            void getSettingsAttributes(char const*& _buffer, uint32_t& attrBitset);

            void requestIdentityUnbind(char const*& _buffer, std::string& identifier, IdentityProvider& provider);

            void getMessagesBySequenceNumber(char const*& _buffer, std::string& channelId, std::string& messageBoxId, uint64_t& startSeq, uint64_t& endSeq);

            void inviteIntoRoom(char const*& _buffer, uint32_t& reqSeq, std::string& roomId, std::vector<std::string>& contactIds);

            void sendChatChecked(char const*& _buffer, uint32_t& seq, std::string& consumer, std::string& lastMessageId, uint32_t& sessionId);

            void removeSnsId(char const*& _buffer, SnsIdType& snsIdType);

            void reportSpammer(char const*& _buffer, std::string& spammerMid, std::vector<SpammerReason>& spammerReasons, std::vector<std::string>& spamMessageIds, std::vector<std::string>& spamMessages);

            void findAndAddContactsByEmail(char const*& _buffer, uint32_t& reqSeq, std::set<std::string>& emails);

            void getCompactGroups(char const*& _buffer, std::vector<std::string>& groupIds);

            void sendMessage(char const*& _buffer, uint32_t& seq, Message& message);

            void getRooms(char const*& _buffer, std::vector<std::string>& roomIds);

            void updateC2DMRegistrationId(char const*& _buffer, std::string& registrationId);

            void sendPostback(char const*& _buffer, SendPostbackRequest& request);

            void getReadMessageOpsInBulk(char const*& _buffer, std::vector<std::string>& chatIds);

            void sendMessageIgnored(char const*& _buffer, uint32_t& seq, std::string& consumer, std::vector<std::string>& messageIds);

            void getMessageBoxWrapUpListV2(char const*& _buffer, uint32_t& messageBoxOffset, uint32_t& messageBoxCount);

            void getOldReadMessageOpsWithRange(char const*& _buffer, uint64_t& startRev, uint64_t& endRev);

            void getRSAKeyInfo(char const*& _buffer, IdentityProvider& provider);

            void updateProfileAttribute(char const*& _buffer, uint32_t& reqSeq, ProfileAttribute& attr, std::string& value);

            void createAccountMigrationPincodeSession(char const*& _buffer);

            void notifiedRedirect(char const*& _buffer, std::map<std::string, std::string>& paramMap);

            void notifyIndividualEvent(char const*& _buffer, NotificationStatus& notificationStatus, std::vector<std::string>& receiverMids);

            void updateApnsDeviceToken(char const*& _buffer, std::string& apnsDeviceToken);

            void getMessageBoxCompactWrapUpListV2(char const*& _buffer, uint32_t& messageBoxOffset, uint32_t& messageBoxCount);

            void requestEmailConfirmation(char const*& _buffer, EmailConfirmation& emailConfirmation);

            void registerWithSnsIdAndIdentityCredential(char const*& _buffer, SnsIdType& snsIdType, std::string& snsAccessToken, IdentityCredential& identityCredential, std::string& region, std::string& udidHash, DeviceInfo& deviceInfo, std::string& migrationPincodeSessionId);

            void getMessageBoxCompactWrapUp(char const*& _buffer, std::string& mid);

            void findContactByUserTicket(char const*& _buffer, std::string& ticketIdWithTag);

            void updateAccountMigrationPincode(char const*& _buffer, std::string& accountMigrationPincode);

            void registerBuddyUser(char const*& _buffer, std::string& buddyId, std::string& registrarPassword);

            void updateSettingsV2(char const*& _buffer, uint32_t& reqSeq, Settings& settings);

            void getUserTicket(char const*& _buffer);

            void fetchOps(char const*& _buffer, uint64_t& localRev, uint32_t& count, uint64_t& globalRev, uint64_t& individualRev);

            void commitSendMessagesToMid(char const*& _buffer, CommitSendMessagesToMidRequest& request);

            void getMessageBoxV2(char const*& _buffer, std::string& messageBoxId, uint32_t& lastMessagesCount);

            void requestResendMessage(char const*& _buffer, uint32_t& reqSeq, std::string& senderMid, std::string& messageId);

            void getGroupWithoutMembers(char const*& _buffer, std::string& groupId);

            void removeAllMessages(char const*& _buffer, uint32_t& seq, std::string& lastMessageId);

            void verifyAccountMigration(char const*& _buffer, std::string& migrationSessionId);

            void reissueGroupTicket(char const*& _buffer, std::string& groupMid);

            void logoutSession(char const*& _buffer, std::string& tokenKey);

            void getBuddyLocation(char const*& _buffer, std::string& mid, uint32_t& index);

            void getWapInvitation(char const*& _buffer, std::string& invitationHash);

            void registerDevice(char const*& _buffer, std::string& sessionId, std::string& migrationPincodeSessionId);

            void clearMessageBox(char const*& _buffer, std::string& channelId, std::string& messageBoxId);

            void loginWithIdentityCredentialForCertificate(char const*& _buffer, std::string& identifier, std::string& password, bool& keepLoggedIn, std::string& accessLocation, std::string& systemName, IdentityProvider& identityProvider, std::string& certificate);

            void getSuggestSettings(char const*& _buffer, std::string& locale);

            void updateAndGetNearby(char const*& _buffer, double& latitude, double& longitude);

            void syncContactBySnsIds(char const*& _buffer, uint32_t& reqSeq, std::vector<SnsFriendModification>& modifications);

            void getContacts(char const*& _buffer, std::vector<std::string>& ids);

            void getMessageBoxCompactWrapUpList(char const*& _buffer, uint32_t& start, uint32_t& messageBoxCount);

            void getProximityMatchCandidates(char const*& _buffer, std::string& sessionId);

            void updateExtendedProfileAttribute(char const*& _buffer, uint32_t& reqSeq, ExtendedProfileAttribute& attr, ExtendedProfile& extendedProfile);

            void resendPinCode(char const*& _buffer, std::string& sessionId);

            void reportSettings(char const*& _buffer, uint64_t& syncOpRevision, Settings& settings);

            void registerBuddyUserid(char const*& _buffer, uint32_t& seq, std::string& userid);

            void findGroupByTicket(char const*& _buffer, std::string& ticketId);

            void registerDeviceWithIdentityCredential(char const*& _buffer, std::string& sessionId, std::string& identifier, std::string& verifier, IdentityProvider& provider, std::string& migrationPincodeSessionId);

            void invalidateUserTicket(char const*& _buffer);

            void sendEvent(char const*& _buffer, uint32_t& seq, Message& message);

            void sendMessageToMyHome(char const*& _buffer, uint32_t& seq, Message& message);

            void sendContentPreviewUpdated(char const*& _buffer, uint32_t& esq, std::string& messageId, std::vector<std::string>& receiverMids);

            void loginWithVerifier(char const*& _buffer, std::string& verifier);

            void removeBuddySubscriptionAndNotifyBuddyUnregistered(char const*& _buffer, std::vector<std::string>& subscriberMids);

            void unblockContact(char const*& _buffer, uint32_t& reqSeq, std::string& id, std::string& reference);

            void removeBuddyLocation(char const*& _buffer, std::string& mid, uint32_t& index);

            void getRingbackTone(char const*& _buffer);

            void getConfigurations(char const*& _buffer, uint64_t& revision, std::string& regionOfUsim, std::string& regionOfTelephone, std::string& regionOfLocale, std::string& carrier);

            void getProximityMatchCandidateList(char const*& _buffer, std::string& sessionId);

            void requestAccountPasswordReset(char const*& _buffer, std::string& identifier, IdentityProvider& provider, std::string& locale);

            void getNextMessages(char const*& _buffer, std::string& messageBoxId, uint64_t& startSeq, uint32_t& messagesCount);

            void reportProfile(char const*& _buffer, uint64_t& syncOpRevision, Profile& profile);

            void getCompactRoom(char const*& _buffer, std::string& roomId);

            void getLastOpRevision(char const*& _buffer);

            void getPreviousMessagesV2(char const*& _buffer, std::string& messageBoxId, MessageBoxV2MessageId& endMessageId, uint32_t& messagesCount);

            void fetchAnnouncements(char const*& _buffer, uint32_t& lastFetchedIndex);

            void acquireCallRoute(char const*& _buffer, std::string& to);

            void updateSettingsAttribute(char const*& _buffer, uint32_t& reqSeq, SettingsAttribute& attr, std::string& value);

            void createGroupV2(char const*& _buffer, uint32_t& seq, std::string& name, std::vector<std::string>& contactIds);

            void isIdentityIdentifierAvailable(char const*& _buffer, std::string& identifier, IdentityProvider& provider);

            void blockContact(char const*& _buffer, uint32_t& reqSeq, std::string& id);

            void commitUpdateProfile(char const*& _buffer, uint32_t& seq, std::vector<ProfileAttribute>& attrs, std::vector<std::string>& receiverMids);

            void registerWithSnsId(char const*& _buffer, SnsIdType& snsIdType, std::string& snsAccessToken, std::string& region, std::string& udidHash, DeviceInfo& deviceInfo, std::string& mid, std::string& migrationPincodeSessionId);

            void updatePublicKeychain(char const*& _buffer, PublicKeychain& publicKeychain);

            void loginWithVerifierForCerificate(char const*& _buffer, std::string& verifier);

            void tryFriendRequest(char const*& _buffer, std::string& midOrEMid, FriendRequestMethod& method, std::string& friendRequestParams);

            void getBlockedRecommendationIds(char const*& _buffer);

            void getGroupIdsInvited(char const*& _buffer);

            void getSuggestIncrements(char const*& _buffer, SuggestDictionaryRevisions& revisions);

            void resendPinCodeBySMS(char const*& _buffer, std::string& sessionId);

            void registerWithPhoneNumber(char const*& _buffer, std::string& sessionId, std::string& migrationPincodeSessionId);

            void getActiveBuddySubscriberIds(char const*& _buffer);

            void createRoom(char const*& _buffer, uint32_t& reqSeq, std::vector<std::string>& contactIds);

            void verifyPhoneNumberForLogin(char const*& _buffer, std::string& verifierFromPhone, std::string& pinCodeForPhone, std::string& verifierFromLogin);

            void addSnsId(char const*& _buffer, SnsIdType& snsIdType, std::string& snsAccessToken);

            void finishUpdateVerification(char const*& _buffer, std::string& sessionId);

            void validateContactsOnBot(char const*& _buffer, std::vector<std::string>& contacts);

            void getRoom(char const*& _buffer, std::string& roomId);

            void closeProximityMatch(char const*& _buffer, std::string& sessionId);

            void getCompactGroup(char const*& _buffer, std::string& groupId);

            void getBlockedContactIdsByRange(char const*& _buffer, uint32_t& start, uint32_t& count);

            void getRecentMessagesV2(char const*& _buffer, std::string& messageBoxId, uint32_t& messagesCount);

            void reissueUserTicket(char const*& _buffer, uint64_t& expirationTime, uint32_t& maxUseCount);

            void getMessageReadRange(char const*& _buffer, std::vector<std::string>& chatIds);

            void clearRingbackTone(char const*& _buffer);

            void setIdentityCredential(char const*& _buffer, std::string& identifier, std::string& verifier, IdentityProvider& provider);

            void getMessageBoxCompactWrapUpV2(char const*& _buffer, std::string& messageBoxId);

            void getServerTime(char const*& _buffer);

            void trySendMessage(char const*& _buffer, uint32_t& seq, Message& message);

            void getNextMessagesV2(char const*& _buffer, std::string& messageBoxId, MessageBoxV2MessageId& startMessageId, uint32_t& messagesCount);

            void notifySleep(char const*& _buffer, uint64_t& lastRev, uint32_t& badge);

            void getBuddyBlockerIds(char const*& _buffer);

            void removeE2EEPublicKey(char const*& _buffer, E2EEPublicKey& publicKey);

            void reissueTrackingTicket(char const*& _buffer, TrackingType& type);

            void cancelGroupInvitation(char const*& _buffer, uint32_t& reqSeq, std::string& groupId, std::vector<std::string>& contactIds);

            void removeMessage(char const*& _buffer, std::string& messageId);

            void getAllReadMessageOps(char const*& _buffer);

            void unregisterUserAndDevice(char const*& _buffer);

            void acceptGroupInvitation(char const*& _buffer, uint32_t& reqSeq, std::string& groupId);

            void getCompactContactsModifiedSince(char const*& _buffer, uint64_t& timestamp);

            void releaseSession(char const*& _buffer);

            void findContactsByPhone(char const*& _buffer, std::set<std::string>& phones);

            void getHiddenContactMids(char const*& _buffer);

            void getEncryptedIdentity(char const*& _buffer);

            void updateProfile(char const*& _buffer, uint32_t& reqSeq, Profile& profile);

            void reportSpam(char const*& _buffer, std::string& chatMid, std::vector<std::string>& memberMids, std::vector<SpammerReason>& spammerReasons, std::vector<std::string>& senderMids, std::vector<std::string>& spamMessageIds, std::vector<std::string>& spamMessages);

            void getSuggestRevisions(char const*& _buffer);

            void getPreviousMessagesV2WithReadCount(char const*& _buffer, std::string& messageBoxId, MessageBoxV2MessageId& endMessageId, uint32_t& messagesCount);

            void fetchOperations(char const*& _buffer, uint64_t& localRev, uint32_t& count);

            void registerWapDevice(char const*& _buffer, std::string& invitationHash, std::string& guidHash, std::string& email, DeviceInfo& deviceInfo);

            void getRecentFriendRequests(char const*& _buffer);

            void notifyBuddyOnAir(char const*& _buffer, uint32_t& seq, std::vector<std::string>& receiverMids);

            void getLastAnnouncementIndex(char const*& _buffer);

            void sendMessageAwaitCommit(char const*& _buffer, uint32_t& seq, Message& message);

            void negotiateE2EEPublicKey(char const*& _buffer, std::string& mid);

            void registerE2EEGroupKey(char const*& _buffer, uint32_t& version, std::string& chatMid, std::vector<std::string>& members, std::vector<uint32_t>& keyIds, std::vector<std::string>& encryptedSharedKeys);

            void findSnsIdUserStatus(char const*& _buffer, SnsIdType& snsIdType, std::string& snsAccessToken, std::string& udidHash, std::string& migrationPincodeSessionId, std::string& oldUdidHash);

            void notifyUpdated(char const*& _buffer, uint64_t& lastRev, DeviceInfo& deviceInfo, std::string& udidHash, std::string& oldUdidHash);

            void reportGroups(char const*& _buffer, uint64_t& syncOpRevision, std::vector<Group>& groups);

            void getNotificationPolicy(char const*& _buffer, CarrierCode& carrier);

            void findAndAddContactsByUserid(char const*& _buffer, uint32_t& reqSeq, std::set<std::string>& userids);

            void getLastE2EEGroupSharedKey(char const*& _buffer, uint32_t& version, std::string& chatMid);

            void notifyUpdatePublicKeychain(char const*& _buffer, std::string& mid);

            void report(char const*& _buffer, uint64_t& syncOpRevision, SyncCategory& category, std::string& report);

            void acceptGroupInvitationByTicket(char const*& _buffer, uint32_t& reqSeq, std::string& groupMid, std::string& ticketId);

            void getContactRegistration(char const*& _buffer, std::string& id, ContactType& type);

            void updateContactSetting(char const*& _buffer, uint32_t& reqSeq, std::string& mid, ContactSetting& flag, std::string& value);

            void getContactWithFriendRequestStatus(char const*& _buffer, std::string& id);

            void getMessageBoxListByStatus(char const*& _buffer, std::string& channelId, uint32_t& lastMessagesCount, uint32_t& status);

            void openProximityMatch(char const*& _buffer, Location& location);

            void logout(char const*& _buffer);

            void getE2EEPublicKey(char const*& _buffer, std::string& mid, uint32_t& version, uint32_t& keyId);

            void registerUserid(char const*& _buffer, uint32_t& reqSeq, std::string& userid);

            void reportContacts(char const*& _buffer, uint64_t& syncOpRevision, SyncCategory& category, std::vector<ContactReport>& contactReports, SyncActionType& actionType);

            void getPublicKeychain(char const*& _buffer, std::string& mid);

            void sendContentReceipt(char const*& _buffer, uint32_t& seq, std::string& consumer, std::string& messageId);

            void respondResendMessage(char const*& _buffer, uint32_t& reqSeq, std::string& receiverMid, std::string& originalMessageId, Message& resendMessage, ErrorCode& errorCode);

            void getAllRoomIds(char const*& _buffer);

            void requestE2EEKeyExchange(char const*& _buffer, uint32_t& reqSeq, std::string& temporalPublicKey, E2EEPublicKey& publicKey, std::string& verifier);

            void disableNearby(char const*& _buffer);

            void createQrcodeBase64Image(char const*& _buffer, std::string& url, std::string& characterSet, uint32_t& imageSize, uint32_t& x, uint32_t& y, uint32_t& width, uint32_t& height);

            void getMessageBoxList(char const*& _buffer, std::string& channelId, uint32_t& lastMessagesCount);

            void respondE2EEKeyExchange(char const*& _buffer, uint32_t& reqSeq, std::string& encryptedKeyChain, std::string& hashKeyChain);

            void verifyQrcode(char const*& _buffer, std::string& verifier, std::string& pinCode);

            void updateNotificationTokenWithBytes(char const*& _buffer, std::string& token, NotificationType& type);

            void getPreviousMessages(char const*& _buffer, std::string& messageBoxId, uint64_t& endSeq, uint32_t& messagesCount);

            void getSettings(char const*& _buffer);

            void getLastE2EEPublicKeys(char const*& _buffer, std::string& chatMid);

            void registerE2EEPublicKey(char const*& _buffer, uint32_t& reqSeq, E2EEPublicKey& publicKey);

            void acquireCallTicket(char const*& _buffer, std::string& to);

            void inviteIntoGroup(char const*& _buffer, uint32_t& reqSeq, std::string& groupId, std::vector<std::string>& contactIds);

            void makeUserAddMyselfAsContact(char const*& _buffer, std::string& contactOwnerMid);

            void removeMessageFromMyHome(char const*& _buffer, std::string& messageId);

            void commitSendMessages(char const*& _buffer, uint32_t& seq, std::vector<std::string>& messageIds, std::vector<std::string>& receiverMids, bool& onlyToFollowers);

            void registerWithPhoneNumberAndPassword(char const*& _buffer, std::string& sessionId, std::string& keynm, std::string& encrypted);

            void leaveGroup(char const*& _buffer, uint32_t& reqSeq, std::string& groupId);

            void getAnalyticsInfo(char const*& _buffer);

            void reportClientStatistics(char const*& _buffer, uint32_t& reqSeq, ReportCategory& category, uint32_t& count);

            void acceptProximityMatches(char const*& _buffer, std::string& sessionId, std::set<std::string>& ids);

            void getGroup(char const*& _buffer, std::string& groupId);

            void clearIdentityCredential(char const*& _buffer);

            void getUpdatedMessageBoxIds(char const*& _buffer, MessageBoxV2MessageId& startMessageId, std::string& startMessageBoxId, uint32_t& messageBoxCount);

            void getGroups(char const*& _buffer, std::vector<std::string>& groupIds);

            void sendMessageReceipt(char const*& _buffer, uint32_t& seq, std::string& consumer, std::vector<std::string>& messageIds);

            void findContactByMetaTag(char const*& _buffer, std::string& userid, std::string& reference);

            void destroyMessage(char const*& _buffer, uint32_t& seq, std::string& chatId, std::string& messageId, uint32_t& sessionId);

            void generateUserTicket(char const*& _buffer, uint64_t& expirationTime, uint32_t& maxUseCount);

            void registerDeviceWithoutPhoneNumberWithIdentityCredential(char const*& _buffer, std::string& region, std::string& udidHash, DeviceInfo& deviceInfo, IdentityProvider& provider, std::string& identifier, std::string& verifier, std::string& mid, std::string& migrationPincodeSessionId);

            void getFavoriteMids(char const*& _buffer);

            void getAcceptedProximityMatches(char const*& _buffer, std::string& sessionId);

            void notifyInstalled(char const*& _buffer, std::string& udidHash, std::string& applicationTypeWithExtensions);

            void getCountryWithRequestIp(char const*& _buffer);

            void getGroupsV2(char const*& _buffer, std::vector<std::string>& groupIds);

            void loginWithIdentityCredential(char const*& _buffer, std::string& identifier, std::string& password, bool& keepLoggedIn, std::string& accessLocation, std::string& systemName, IdentityProvider& identityProvider, std::string& certificate);

            void startUpdateVerification(char const*& _buffer, std::string& region, CarrierCode& carrier, std::string& phone, std::string& udidHash, DeviceInfo& deviceInfo, std::string& networkCode, std::string& locale, SIMInfo& simInfo);

            void getSessions(char const*& _buffer);

            void updateSettings(char const*& _buffer, uint32_t& reqSeq, Settings& settings);

            void getContact(char const*& _buffer, std::string& id);

            void getBlockedContactIds(char const*& _buffer);

            void loginWithVerifierForCertificate(char const*& _buffer, std::string& verifier);

            void getProfile(char const*& _buffer);

            void findContactsByEmail(char const*& _buffer, std::set<std::string>& emails);

            void getSystemConfiguration(char const*& _buffer);

            void getRecentMessages(char const*& _buffer, std::string& messageBoxId, uint32_t& messagesCount);

            void verifyPhone(char const*& _buffer, std::string& sessionId, std::string& pinCode, std::string& udidHash);

            void createGroup(char const*& _buffer, uint32_t& seq, std::string& name, std::vector<std::string>& contactIds);

            void updateBuddySetting(char const*& _buffer, std::string& key, std::string& value);

            void updateRegion(char const*& _buffer, std::string& region);

            void verifyIdentityCredential(char const*& _buffer, std::string& identifier, std::string& password, IdentityProvider& identityProvider);

            void sendChatRemoved(char const*& _buffer, uint32_t& seq, std::string& consumer, std::string& lastMessageId, uint32_t& sessionId);

            void getGroupIdsJoined(char const*& _buffer);

            void findContactByUserid(char const*& _buffer, std::string& userid);

            void getE2EEPublicKeys(char const*& _buffer);

            void getMessageBoxWrapUpList(char const*& _buffer, uint32_t& start, uint32_t& messageBoxCount);

            void leaveRoom(char const*& _buffer, uint32_t& reqSeq, std::string& roomId);

            void unblockRecommendation(char const*& _buffer, uint32_t& reqSeq, std::string& id);

            void findAndAddContactsByPhone(char const*& _buffer, uint32_t& reqSeq, std::set<std::string>& phones);

            void getAuthQrcode(char const*& _buffer, bool& keepLoggedIn, std::string& systemName, bool& returnCallbackUrl);

            void getE2EEGroupSharedKey(char const*& _buffer, uint32_t& version, std::string& chatMid, uint32_t& groupKeyId);

            void getMessageBoxWrapUp(char const*& _buffer, std::string& mid);

            void updateSettingsAttributes(char const*& _buffer, uint32_t& reqSeq, uint32_t& attrBitset, Settings& settings);

            void startVerification(char const*& _buffer, std::string& region, CarrierCode& carrier, std::string& phone, std::string& udidHash, DeviceInfo& deviceInfo, std::string& networkCode, std::string& mid, std::string& locale, SIMInfo& simInfo, std::string& oldUdidHash);

            void reportRooms(char const*& _buffer, uint64_t& syncOpRevision, std::vector<Room>& rooms);

            void updateGroupPreferenceAttribute(char const*& _buffer, uint32_t& reqSeq, std::string& groupMid, std::map<GroupPreferenceAttribute, std::string>& updatedAttrs);

            void getMessageBoxWrapUpV2(char const*& _buffer, std::string& messageBoxId);

            void getCompactRooms(char const*& _buffer, std::vector<std::string>& roomIds);

            void findAndAddContactByMetaTag(char const*& _buffer, uint32_t& reqSeq, std::string& userid, std::string& reference);

            void storeUpdateProfileAttribute(char const*& _buffer, uint32_t& seq, ProfileAttribute& profileAttribute, std::string& value);

            void resendEmailConfirmation(char const*& _buffer, std::string& verifier);

            void confirmEmail(char const*& _buffer, std::string& verifier, std::string& pinCode);

            void getExtendedProfile(char const*& _buffer);

            void isUseridAvailable(char const*& _buffer, std::string& userid);

            void notifyRegistrationComplete(char const*& _buffer, std::string& udidHash, std::string& applicationTypeWithExtensions);

            void updateDeviceInfo(char const*& _buffer, std::string& deviceUid, DeviceInfo& deviceInfo);

            void blockRecommendation(char const*& _buffer, uint32_t& reqSeq, std::string& id);

            void rejectGroupInvitation(char const*& _buffer, uint32_t& reqSeq, std::string& groupId);

            void updateCustomModeSettings(char const*& _buffer, CustomMode& customMode, std::map<std::string, std::string>& paramMap);

            void createRoomV2(char const*& _buffer, uint32_t& reqSeq, std::vector<std::string>& contactIds);

            void noop(char const*& _buffer);

            void acquireEncryptedAccessToken(char const*& _buffer, FeatureType& featureType);

            void getE2EEPublicKeysEx(char const*& _buffer, bool& ignoreE2EEStatus);

            void syncContacts(char const*& _buffer, uint32_t& reqSeq, std::vector<ContactModification>& localContacts);

            void findAndAddContactsByMid(char const*& _buffer, uint32_t& reqSeq, std::set<std::string>& mids);

            void findGroupByTicketV2(char const*& _buffer, std::string& ticketId);

            void removeFriendRequest(char const*& _buffer, FriendRequestDirection& direction, std::string& midOrEMid);

            void verifyPhoneNumber(char const*& _buffer, std::string& sessionId, std::string& pinCode, std::string& udidHash, std::string& migrationPincodeSessionId, std::string& oldUdidHash);

            void setNotificationsEnabled(char const*& _buffer, uint32_t& reqSeq, MIDType& type, std::string& target, bool& enablement);

            void getAllContactIds(char const*& _buffer);

            void getIdentityIdentifier(char const*& _buffer);

            void sendDummyPush(char const*& _buffer);

            void inviteFriendsBySms(char const*& _buffer, std::vector<std::string>& phoneNumberList);

            void getMessageBox(char const*& _buffer, std::string& channelId, std::string& messageBoxId, uint32_t& lastMessagesCount);

            void unsendMessage(char const*& _buffer, uint32_t& reqSeq, std::string& messageId);

            void createChatRoomAnnouncement(char const*& _buffer, uint32_t& reqSeq, std::string& chatRoomMid, uint32_t& type, ChatRoomAnnouncementContents& contents);

            void removeChatRoomAnnouncement(char const*& _buffer, uint32_t& reqSeq, std::string& chatRoomMid, uint64_t& announcementSeq);

            void getChatRoomAnnouncements(char const*& _buffer, std::string& chatRoomMid);

            void getChatRoomAnnouncementsBulk(char const*& _buffer, std::vector<std::string>& chatRoomMids);

            void unregisterBuddy(char const*& _buffer, std::string& requestId);

            void sendBuddyContentMessageToMidsAsync(char const*& _buffer, std::string& requestId, Message& msg, std::string& content, std::vector<std::string>& mids);

            void getAllBuddyMembers(char const*& _buffer);

            void getActiveMemberMidsByBuddyMid(char const*& _buffer, std::string& buddyMid);

            void updateBuddyProfileAttributes(char const*& _buffer, std::string& requestId, std::map<std::string, std::string>& attributes, QueueingPolicy& policy);

            void storePrivateMessages(char const*& _buffer, std::string& requestId, std::vector<PrivateBotMessage>& privateBotMessages, std::string& toMid);

            void updateBuddyProfileImageAsync(char const*& _buffer, std::string& requestId, std::string& image, QueueingPolicy& policy);

            void notifyBuddyBlocked(char const*& _buffer, std::string& buddyMid, std::string& blockerMid);

            void getMemberCountByBuddyMid(char const*& _buffer, std::string& buddyMid);

            void isBuddyOnAirByMid(char const*& _buffer, std::string& buddyMid);

            void commitPrivateMessages(char const*& _buffer, std::string& requestId, std::string& privateMessageStoreRequestId, QueueingPolicy& policy);

            void commitPublicMessagesToMids(char const*& _buffer, std::string& requestId, std::string& publicMessageStoreRequestId, std::vector<std::string>& toMids, QueueingPolicy& policy);

            void addBuddyMember(char const*& _buffer, std::string& requestId, std::string& userMid);

            void linkAndSendBuddyContentMessageToMids(char const*& _buffer, std::string& requestId, Message& msg, std::string& sourceContentId, std::vector<std::string>& mids, bool& usePermanent);

            void storeMessages(char const*& _buffer, std::vector<std::string>& requestIds, std::vector<BuddyMessageRequest>& messageRequests);

            void storeMessage(char const*& _buffer, std::string& requestId, BuddyMessageRequest& messageRequest);

            void registerBuddy(char const*& _buffer, std::string& buddyId, std::string& searchId, std::string& displayName, std::string& statusMeessage, std::string& picture, std::map<std::string, std::string>& settings);

            void getUnregisterBuddyResult(char const*& _buffer, std::string& unregisterBuddyRequestId, std::string& buddyMid);

            void updateBuddySearchId(char const*& _buffer, std::string& requestId, std::string& searchId);

            void uploadBuddyContent(char const*& _buffer, ContentType& contentType, std::string& content);

            void updateBuddyProfileImage(char const*& _buffer, std::string& requestId, std::string& image, QueueingPolicy& policy);

            void sendBuddyMessageToAll(char const*& _buffer, std::string& requestId, Message& msg);

            void commitSendMessagesToAll(char const*& _buffer, std::string& requestId, std::vector<std::string>& commitRequestIdList, uint32_t& priority, QueueingPolicy& policy);

            void downloadMessageContent(char const*& _buffer, std::string& requestId, std::string& messageId);

            void updateBuddyProfileRichMenu(char const*& _buffer, std::string& requestId, QueueingPolicy& policy);

            void setBuddyOnAir(char const*& _buffer, std::string& requestId, bool& onAir, BuddyOnAirLabel& label);

            void unblockBuddyMember(char const*& _buffer, std::string& requestId, std::string& mid);

            void linkAndSendBuddyContentMessageToAll(char const*& _buffer, std::string& requestId, Message& msg, std::string& sourceContentId, bool& usePermanent);

            void removeBuddyMember(char const*& _buffer, std::string& requestId, std::string& userMid);

            void commitSendMessagesToMidAsync(char const*& _buffer, std::string& requestId, std::vector<std::string>& storeMessagesRequestIds, QueueingPolicy& policy);

            void getUpdateBuddyProfileResult(char const*& _buffer, std::string& updateBuddyProfileRequestId);

            void notifyBuddyUnblocked(char const*& _buffer, std::string& buddyMid, std::string& blockerMid);

            void updateBuddyProfileRichMenuAsync(char const*& _buffer, std::string& requestId, QueueingPolicy& policy);

            void getBuddyProfile(char const*& _buffer);

            void getBlockedBuddyMembers(char const*& _buffer);

            void commitPublicMessagesToAll(char const*& _buffer, std::string& requestId, std::string& publicMessageStoreRequestId, QueueingPolicy& policy);

            void linkAndSendBuddyContentMessageToAllAsync(char const*& _buffer, std::string& requestId, Message& msg, std::string& sourceContentId, bool& usePermanent);

            void sendBuddyContentMessageToAllAsync(char const*& _buffer, std::string& requestId, Message& msg, std::string& content);

            void getSetBuddyOnAirResult(char const*& _buffer, std::string& setBuddyOnAirRequestId);

            void commitSendMessagesToMidsAsync(char const*& _buffer, std::string& requestId, std::vector<std::string>& commitRequestIdList, std::vector<std::string>& mids, uint32_t& priority, QueueingPolicy& policy);

            void commitSendMessagesToStoredMidsAsync(char const*& _buffer, std::string& requestId, std::vector<std::string>& commitRequestIdList, std::string& storedMidFilename, uint32_t& priority, QueueingPolicy& policy);

            void updateBuddyAdminProfileAttribute(char const*& _buffer, std::string& requestId, std::map<std::string, std::string>& attributes);

            void setBuddyOnAirAsync(char const*& _buffer, std::string& requestId, bool& onAir, BuddyOnAirLabel& label);

            void commitSendMessagesToMids(char const*& _buffer, std::string& requestId, std::vector<std::string>& commitRequestIdList, std::vector<std::string>& mids, uint32_t& priority, QueueingPolicy& policy);

            void sendBuddyContentMessageToAll(char const*& _buffer, std::string& requestId, Message& msg, std::string& content);

            void updateBuddySettings(char const*& _buffer, std::map<std::string, std::string>& settings);

            void notifyBuddySubscribed(char const*& _buffer, std::string& buddyMid, std::string& subscriberMid);

            void registerBuddyAdmin(char const*& _buffer, std::string& buddyId, std::string& searchId, std::string& displayName, std::string& statusMessage, std::string& picture);

            void getBlockerCountByBuddyMid(char const*& _buffer, std::string& buddyMid);

            void reissueContactTicket(char const*& _buffer, uint64_t& expirationTime, uint32_t& maxUseCount);

            void validateContacts(char const*& _buffer, std::vector<std::string>& userMids);

            void sendBuddyMessageToMidsAsync(char const*& _buffer, std::string& requestId, Message& msg, std::vector<std::string>& mids);

            void unregisterBuddyAsync(char const*& _buffer, std::string& requestId);

            void getProfileImageUrlHash(char const*& _buffer, std::string& requestId);

            void blockBuddyMember(char const*& _buffer, std::string& requestId, std::string& mid);

            void sendIndividualEventToAllAsync(char const*& _buffer, std::string& requestId, std::string& buddyMid, NotificationStatus& notificationStatus);

            void deleteBotProfileImage(char const*& _buffer, std::string& requestId);

            void sendBuddyContentMessageToMids(char const*& _buffer, std::string& requestId, Message& msg, std::string& content, std::vector<std::string>& mids);

            void unregisterBuddyAdmin(char const*& _buffer, std::string& requestId);

            void commitPublicMessagesToStoredMids(char const*& _buffer, std::string& requestId, std::string& publicMessageStoreRequestId, std::string& storedMidFilename, QueueingPolicy& policy);

            void removeBuddyMembers(char const*& _buffer, std::string& requestId, std::vector<std::string>& userMids);

            void storePublicMessages(char const*& _buffer, std::string& requestId, std::vector<Message>& messages);

            void addBuddyMembers(char const*& _buffer, std::string& requestId, std::vector<std::string>& userMids);

            void getMessageCommitResult(char const*& _buffer, std::string& messageCommitRequestId);

            void getBuddyDetailByMid(char const*& _buffer, std::string& buddyMid);

            void notifyBuddySubscriberUnregistered(char const*& _buffer, std::string& buddyMid, std::string& userMid);

            void sendBuddyMessageToAllAsync(char const*& _buffer, std::string& requestId, Message& msg);

            void sendBuddyMessageToMids(char const*& _buffer, std::string& requestId, Message& msg, std::vector<std::string>& mids);

            void commitSendMessagesToAllAsync(char const*& _buffer, std::string& requestId, std::vector<std::string>& commitRequestIdList, uint32_t& priority, QueueingPolicy& policy);

            void notifyBuddySubscriberEmpty(char const*& _buffer, std::string& buddyMid, std::string& userMid);

            void updateBuddyAdminProfileImage(char const*& _buffer, std::string& requestId, std::string& picture);

            void updateBuddyProfileAttributesAsync(char const*& _buffer, std::string& requestId, std::map<std::string, std::string>& attributes, QueueingPolicy& policy);

            void linkAndSendBuddyContentMessageToMidsAsync(char const*& _buffer, std::string& requestId, Message& msg, std::string& sourceContentId, std::vector<std::string>& mids, bool& usePermanent);

            void downloadProfileImagePreview(char const*& _buffer, std::string& requestId);

            void downloadProfileImage(char const*& _buffer, std::string& requestId);

            void getSendBuddyMessageResult(char const*& _buffer, std::string& sendBuddyMessageRequestId);

            void containsBuddyMember(char const*& _buffer, std::string& requestId, std::string& userMid);

            void getActiveMemberCountByBuddyMid(char const*& _buffer, std::string& buddyMid);

            void downloadMessageContentPreview(char const*& _buffer, std::string& requestId, std::string& messageId);

            void notifyBuddyRegistered(char const*& _buffer, std::string& buddyId, std::string& buddyMid, std::string& searchId, std::string& displayName, std::string& statusMessage, std::map<std::string, std::string>& settings);

            void lookupByPhoneNumber(char const*& _buffer, std::string& countryAreaCode, std::string& phoneNumber);

            void lookupNearby(char const*& _buffer, Location& location, SpotCategory& category, std::string& query, std::string& countryAreaCode);

            void checkUserAge(char const*& _buffer, CarrierCode& carrier, std::string& sessionId, std::string& verifier, uint32_t& standardAge);

            void checkUserAgeWithDocomo(char const*& _buffer, std::string& openIdRedirectUrl, uint32_t& standardAge, std::string& verifier);

            void retrieveOpenIdAuthUrlWithDocomo(char const*& _buffer);

            void retrieveRequestToken(char const*& _buffer, CarrierCode& carrier);

            void getBuddyStatusBar(char const*& _buffer, std::string& buddyMid, uint64_t& revision);

            void getRichMenuContents(char const*& _buffer, std::string& buddyMid, uint64_t& revision);

            void getBuddyProfilePopup(char const*& _buffer, std::string& buddyMid);

            void getPopularBuddyBanner(char const*& _buffer, std::string& language, std::string& country, ApplicationType& applicationType, std::string& resourceSpecification);

            void getPopularBuddyLists(char const*& _buffer, std::string& language, std::string& country);

            void findBuddyContactsByQuery(char const*& _buffer, std::string& language, std::string& country, std::string& query, uint32_t& fromIndex, uint32_t& count, BuddySearchRequestSource& requestSource);

            void getBuddyNewsView(char const*& _buffer, std::string& language, std::string& country, uint64_t& offset, uint32_t& limit);

            void getBuddyContacts(char const*& _buffer, std::string& language, std::string& country, std::string& classification, uint32_t& fromIndex, uint32_t& count);

            void getBuddyCollectionEntries(char const*& _buffer, std::string& language, std::string& country, uint32_t& collection, uint32_t& offset, uint32_t& limit);

            void getLatestBuddyNewsTimestamp(char const*& _buffer, std::string& country);

            void getBuddyChatBar(char const*& _buffer, std::string& buddyMid, uint64_t& revision);

            void getCountriesServingOfficialAccountPromotionV2(char const*& _buffer);

            void getBuddyDetail(char const*& _buffer, std::string& buddyMid);

            void getBuddyOnAir(char const*& _buffer, std::string& buddyMid);

            void getNewlyReleasedBuddyIds(char const*& _buffer, std::string& country);

            void getBuddyCategoryView(char const*& _buffer, std::string& language, std::string& country);

            void getCountriesHavingBuddy(char const*& _buffer);

            void getPromotedBuddyContacts(char const*& _buffer, std::string& language, std::string& country);

            void getBuddyTopView(char const*& _buffer, std::string& language, std::string& country);

            void notifyLeaveGroup(char const*& _buffer, std::string& groupMid);

            void notifyLeaveRoom(char const*& _buffer, std::string& roomMid);

            void getBotUseInfo(char const*& _buffer, std::string& botMid);

            void sendChatCheckedByWatermark(char const*& _buffer, uint32_t& seq, std::string& mid, uint64_t& watermark, uint32_t& sessionId);

            void normalizePhoneNumber(char const*& _buffer, std::string& countryCode, std::string& phoneNumber, std::string& countryCodeHint);

            void respondE2EELoginRequest(char const*& _buffer, std::string& verifier, E2EEPublicKey& publicKey, std::string& encryptedKeyChain, std::string& hashKeyChain, ErrorCode& errorCode);

            void confirmE2EELogin(char const*& _buffer, std::string& verifier, std::string& deviceSecret);

            void logoutZ(char const*& _buffer);

            void loginZ(char const*& _buffer, LoginRequest& loginRequest);

            void issueTokenForAccountMigrationSettings(char const*& _buffer, bool& enforce);

            void issueTokenForAccountMigration(char const*& _buffer, std::string& migrationSessionId);

            void verifyQrcodeWithE2EE(char const*& _buffer, std::string& verifier, std::string& pinCode, ErrorCode& errorCode, E2EEPublicKey& publicKey, std::string& encryptedKeyChain, std::string& hashKeyChain);

        } // closing request namespace

        namespace result {

            void ChannelExceptionFunction(char const*& _buffer, std::stack<uint16_t>& _lastField, std::optional<ChannelException>& e);

            void PointExceptionFunction(char const*& _buffer, std::stack<uint16_t>& _lastField, std::optional<PointException>& e);

            void ShouldSyncExceptionFunction(char const*& _buffer, std::stack<uint16_t>& _lastField, std::optional<ShouldSyncException>& e);

            void TalkExceptionFunction(char const*& _buffer, std::stack<uint16_t>& _lastField, std::optional<TalkException>& e);

            void getMoretabRecommend(char const*& _buffer, MoretabRecommend& _result, std::optional<TalkException>& e);

            void requestBanPageForUser(char const*& _buffer, BanPage& _result, std::optional<TalkException>& e);

            void requestBanPage(char const*& _buffer, BanPage& _result, std::optional<TalkException>& e);

            void reserveCoinPurchase(char const*& _buffer, PaymentReservationResult& _result, std::optional<TalkException>& e);

            void getProductCategories(char const*& _buffer, std::vector<ProductCategory>& _result, std::optional<TalkException>& e);

            void getProductList(char const*& _buffer, ProductList& _result, std::optional<TalkException>& e);

            void getCoinPurchaseHistory(char const*& _buffer, CoinHistoryResult& _result, std::optional<TalkException>& e);

            void buyFreeProduct(char const*& _buffer, std::optional<TalkException>& e);

            void getProductListWithCarrier(char const*& _buffer, ProductList& _result, std::optional<TalkException>& e);

            void getDefaultProducts(char const*& _buffer, ProductList& _result, std::optional<TalkException>& e);

            void getProductsForCategory(char const*& _buffer, ProductList& _result, std::optional<TalkException>& e);

            void notifyDownloaded(char const*& _buffer, uint64_t& _result, std::optional<TalkException>& e);

            void getFreePackagesWithoutEvent(char const*& _buffer, ProductList& _result, std::optional<TalkException>& e);

            void getProduct(char const*& _buffer, Product& _result, std::optional<TalkException>& e);

            void getEventPackages(char const*& _buffer, ProductList& _result, std::optional<TalkException>& e);

            void getActivePurchaseVersions(char const*& _buffer, ProductSimpleList& _result, std::optional<TalkException>& e);

            void getCoinProductsByPgCode(char const*& _buffer, std::vector<CoinProductItem>& _result, std::optional<TalkException>& e);

            void getNewlyReleasedPackages(char const*& _buffer, ProductList& _result, std::optional<TalkException>& e);

            void getDownloads(char const*& _buffer, ProductList& _result, std::optional<TalkException>& e);

            void getCoinProducts(char const*& _buffer, std::vector<CoinProductItem>& _result, std::optional<TalkException>& e);

            void searchProducts(char const*& _buffer, ProductList& _result, std::optional<TalkException>& e);

            void buyMustbuyProduct(char const*& _buffer, std::optional<TalkException>& e);

            void getRecommendationsForProduct(char const*& _buffer, ProductList& _result, std::optional<TalkException>& e);

            void getUpdates(char const*& _buffer, ShopUpdates& _result, std::optional<TalkException>& e);

            void getActivePurchases(char const*& _buffer, ProductList& _result, std::optional<TalkException>& e);

            void getProductWithCarrier(char const*& _buffer, Product& _result, std::optional<TalkException>& e);

            void buyCoinProduct(char const*& _buffer, std::optional<TalkException>& e);

            void getPopularPackages(char const*& _buffer, ProductList& _result, std::optional<TalkException>& e);

            void reservePayment(char const*& _buffer, PaymentReservationResult& _result, std::optional<TalkException>& e);

            void getPresentsSent(char const*& _buffer, ProductList& _result, std::optional<TalkException>& e);

            void checkCanReceivePresent(char const*& _buffer, std::optional<TalkException>& e);

            void getFreePackages(char const*& _buffer, ProductList& _result, std::optional<TalkException>& e);

            void getPurchaseHistory(char const*& _buffer, ProductList& _result, std::optional<TalkException>& e);

            void getTotalBalance(char const*& _buffer, Coin& _result, std::optional<TalkException>& e);

            void getCoinUseAndRefundHistory(char const*& _buffer, CoinHistoryResult& _result, std::optional<TalkException>& e);

            void getPresentsReceived(char const*& _buffer, ProductList& _result, std::optional<TalkException>& e);

            void getPlaceSearchInfo(char const*& _buffer, std::vector<PlaceSearchInfo>& _result, std::optional<TalkException>& e);

            void getUserStatus(char const*& _buffer, UserStatus& _result, std::optional<TalkException>& e);

            void updateProfileAttributeForChannel(char const*& _buffer, std::optional<TalkException>& e);

            void getAllSimpleChannelContacts(char const*& _buffer, std::vector<SimpleChannelContact>& _result, std::optional<TalkException>& e);

            void getUserIdentities(char const*& _buffer, std::map<RegistrationType, std::string>& _result, std::optional<TalkException>& e);

            void markPaidCallAd(char const*& _buffer, PaidCallDialing& _result, std::optional<TalkException>& e);

            void isGroupMember(char const*& _buffer, bool& _result, std::optional<TalkException>& e);

            void getPhoneInfoFromPhoneNumber(char const*& _buffer, PhoneInfoForChannel& _result, std::optional<TalkException>& e);

            void redeemPaidCallVoucher(char const*& _buffer, PaidCallRedeemResult& _result, std::optional<TalkException>& e);

            void getPreferredDisplayName(char const*& _buffer, std::map<std::string, std::string>& _result, std::optional<TalkException>& e);

            void getContactsForChannel(char const*& _buffer, std::vector<Contact>& _result, std::optional<TalkException>& e);

            void getCallCreditProducts(char const*& _buffer, std::vector<CoinProductItem>& _result, std::optional<TalkException>& e);

            void getCompactContacts(char const*& _buffer, std::vector<CompactContact>& _result, std::optional<TalkException>& e);

            void notifyNotiCenterEvent(char const*& _buffer, std::optional<TalkException>& e);

            void isInContact(char const*& _buffer, bool& _result, std::optional<TalkException>& e);

            void lookupGroupMembers(char const*& _buffer, std::vector<SimpleChannelContact>& _result, std::optional<TalkException>& e);

            void getRoomInformation(char const*& _buffer, Room& _result, std::optional<TalkException>& e);

            void getGroupCall(char const*& _buffer, GroupCall& _result, std::optional<TalkException>& e);

            void isAllowSecondaryDeviceLogin(char const*& _buffer, bool& _result, std::optional<TalkException>& e);

            void getPrimaryClientForChannel(char const*& _buffer, SimpleChannelClient& _result, std::optional<TalkException>& e);

            void createRoomWithBuddy(char const*& _buffer, Room& _result, std::optional<TalkException>& e);

            void getDisplayName(char const*& _buffer, std::string& _result, std::optional<TalkException>& e);

            void getPaidCallMetadata(char const*& _buffer, PaidCallMetadataResult& _result, std::optional<TalkException>& e);

            void getMid(char const*& _buffer, std::string& _result, std::optional<TalkException>& e);

            void getUserCountryForBilling(char const*& _buffer, std::string& _result, std::optional<TalkException>& e);

            void getFavoriteGroupIdsForChannel(char const*& _buffer, std::vector<std::string>& _result, std::optional<TalkException>& e);

            void getPaidCallHistory(char const*& _buffer, PaidCallHistoryResult& _result, std::optional<TalkException>& e);

            void sendPinCodeOperation(char const*& _buffer, std::optional<TalkException>& e);

            void inviteIntoGroupCall(char const*& _buffer, std::optional<TalkException>& e);

            void getFriendMids(char const*& _buffer, std::vector<std::string>& _result, std::optional<TalkException>& e);

            void getMetaProfile(char const*& _buffer, MetaProfile& _result, std::optional<TalkException>& e);

            void sendMessageForChannel(char const*& _buffer, Message& _result, std::optional<TalkException>& e);

            void activeBuddySubscriberCount(char const*& _buffer, uint64_t& _result, std::optional<TalkException>& e);

            void getCallCreditPurchaseHistory(char const*& _buffer, CoinHistoryResult& _result, std::optional<TalkException>& e);

            void isRoomMember(char const*& _buffer, bool& _result, std::optional<TalkException>& e);

            void sendSystemOAMessage(char const*& _buffer, Message& _result, std::optional<TalkException>& e);

            void acquirePaidCallRoute(char const*& _buffer, PaidCallResponse& _result, std::optional<TalkException>& e);

            void getGroupsForChannel(char const*& _buffer, std::vector<Group>& _result, std::optional<TalkException>& e);

            void getUserCreateTime(char const*& _buffer, uint64_t& _result, std::optional<TalkException>& e);

            void registerChannelCP(char const*& _buffer, std::string& _result, std::optional<TalkException>& e);

            void reserveCallCreditPurchase(char const*& _buffer, PaymentReservationResult& _result, std::optional<TalkException>& e);

            void acquirePaidCallCurrencyExchangeRate(char const*& _buffer, std::vector<PaidCallCurrencyExchangeRate>& _result, std::optional<TalkException>& e);

            void getRoomMemberMidsForAppPlatform(char const*& _buffer, std::vector<std::string>& _result, std::optional<TalkException>& e);

            void getPaidCallBalanceList(char const*& _buffer, std::vector<PaidCallBalance>& _result, std::optional<TalkException>& e);

            void getPersonalInfos(char const*& _buffer, std::map<PersonalInfo, std::string>& _result, std::optional<TalkException>& e);

            void getPrimaryClientsForChannel(char const*& _buffer, std::vector<SimpleChannelClient>& _result, std::optional<TalkException>& e);

            void addBuddyToContact(char const*& _buffer, ContactTransition& _result, std::optional<TalkException>& e);

            void getGroupMemberMidsForAppPlatform(char const*& _buffer, std::vector<std::string>& _result, std::optional<TalkException>& e);

            void getUserLanguage(char const*& _buffer, std::string& _result, std::optional<TalkException>& e);

            void lookupPaidCall(char const*& _buffer, PaidCallResponse& _result, std::optional<TalkException>& e);

            void getReverseCompactContacts(char const*& _buffer, std::map<std::string, CompactContact>& _result, std::optional<TalkException>& e);

            void getPaidCallAdStatus(char const*& _buffer, PaidCallAdResult& _result, std::optional<TalkException>& e);

            void findContactByUseridWithoutAbuseBlockForChannel(char const*& _buffer, Contact& _result, std::optional<TalkException>& e);

            void getGroupMemberMids(char const*& _buffer, std::vector<std::string>& _result, std::optional<TalkException>& e);

            void sendMessageWithoutRelationship(char const*& _buffer, Message& _result, std::optional<TalkException>& e);

            void displayBuddySubscriberCountInBulk(char const*& _buffer, std::map<std::string, uint64_t>& _result, std::optional<TalkException>& e);

            void lookupRoomMembers(char const*& _buffer, std::vector<SimpleChannelContact>& _result, std::optional<TalkException>& e);

            void getFavoriteMidsForChannel(char const*& _buffer, std::vector<std::string>& _result, std::optional<TalkException>& e);

            void getAllContactIdsForChannel(char const*& _buffer, std::vector<std::string>& _result, std::optional<TalkException>& e);

            void displayBuddySubscriberCount(char const*& _buffer, uint64_t& _result, std::optional<TalkException>& e);

            void getProfileForChannel(char const*& _buffer, Profile& _result, std::optional<TalkException>& e);

            void getUserTickets(char const*& _buffer, std::vector<UserTicketResponse>& _result, std::optional<TalkException>& e);

            void getOAFriendMids(char const*& _buffer, std::vector<std::string>& _result, std::optional<TalkException>& e);

            void searchPaidCallUserRate(char const*& _buffer, std::vector<PaidCallUserRate>& _result, std::optional<TalkException>& e);

            void getJoinedGroupIdsForChannel(char const*& _buffer, std::vector<std::string>& _result, std::optional<TalkException>& e);

            void acquireGroupCallRoute(char const*& _buffer, GroupCallRoute& _result, std::optional<TalkException>& e);

            void getUserMidsWhoAddedMe(char const*& _buffer, std::vector<std::string>& _result, std::optional<TalkException>& e);

            void getIdentityCredential(char const*& _buffer, IdentityCredential& _result, std::optional<TalkException>& e);

            void addOperationForChannel(char const*& _buffer, std::optional<TalkException>& e);

            void getSimpleChannelContacts(char const*& _buffer, std::vector<SimpleChannelContact>& _result, std::optional<TalkException>& e);

            void getUserLastSentMessageTimeStamp(char const*& _buffer, uint64_t& _result, std::optional<TalkException>& e);

            void registerVirtualAccount(char const*& _buffer, std::string& _result, std::optional<TalkException>& e);

            void unregisterVirtualAccount(char const*& _buffer, std::optional<TalkException>& e);

            void requestVirtualAccountPasswordChange(char const*& _buffer, std::optional<TalkException>& e);

            void notifyEmailConfirmationResult(char const*& _buffer, std::optional<TalkException>& e);

            void requestVirtualAccountPasswordSet(char const*& _buffer, std::optional<TalkException>& e);

            void getRSAKey(char const*& _buffer, RSAKey& _result, std::optional<TalkException>& e);

            void queryBeaconActions(char const*& _buffer, BeaconQueryResponse& _result, std::optional<TalkException>& e);

            void notifyBeaconDetected(char const*& _buffer, std::optional<TalkException>& e);

            void getDomains(char const*& _buffer, ChannelDomains& _result, std::optional<ChannelException>& e);

            void approveChannelAndIssueRequestToken(char const*& _buffer, std::string& _result, std::optional<ChannelException>& e);

            void issueOTP(char const*& _buffer, OTPResult& _result, std::optional<ChannelException>& e);

            void getChannelSettings(char const*& _buffer, ChannelSettings& _result, std::optional<ChannelException>& e);

            void getChannelNotificationSettings(char const*& _buffer, std::vector<ChannelNotificationSetting>& _result, std::optional<ChannelException>& e);

            void updateChannelNotificationSetting(char const*& _buffer, std::optional<ChannelException>& e);

            void updateChannelSettings(char const*& _buffer, bool& _result, std::optional<ChannelException>& e);

            void getCommonDomains(char const*& _buffer, ChannelDomains& _result, std::optional<ChannelException>& e);

            void issueRequestTokenWithAuthScheme(char const*& _buffer, RequestTokenResponse& _result, std::optional<ChannelException>& e);

            void getChannelNotificationSetting(char const*& _buffer, ChannelNotificationSetting& _result, std::optional<ChannelException>& e);

            void issueChannelToken(char const*& _buffer, ChannelToken& _result, std::optional<ChannelException>& e);

            void getChannels(char const*& _buffer, ChannelInfos& _result, std::optional<ChannelException>& e);

            void fetchNotificationItems(char const*& _buffer, NotificationFetchResult& _result, std::optional<ChannelException>& e);

            void getChannelInfo(char const*& _buffer, ChannelInfo& _result, std::optional<ChannelException>& e);

            void getNotificationBadgeCount(char const*& _buffer, uint32_t& _result, std::optional<ChannelException>& e);

            void issueRequestToken(char const*& _buffer, std::string& _result, std::optional<ChannelException>& e);

            void revokeChannel(char const*& _buffer, std::optional<ChannelException>& e);

            void getApprovedChannels(char const*& _buffer, ApprovedChannelInfos& _result, std::optional<ChannelException>& e);

            void getFriendChannelMatrices(char const*& _buffer, FriendChannelMatricesResponse& _result, std::optional<ChannelException>& e);

            void issueRequestTokenForAutoLogin(char const*& _buffer, std::string& _result, std::optional<ChannelException>& e);

            void getUpdatedChannelIds(char const*& _buffer, std::vector<std::string>& _result, std::optional<ChannelException>& e);

            void reserveCoinUse(char const*& _buffer, std::string& _result, std::optional<ChannelException>& e);

            void syncChannelData(char const*& _buffer, ChannelSyncDatas& _result, std::optional<ChannelException>& e);

            void approveChannelAndIssueChannelToken(char const*& _buffer, ChannelToken& _result, std::optional<ChannelException>& e);

            void getSnsFriends(char const*& _buffer, SnsFriends& _result, std::optional<TalkException>& e);

            void getSnsMyProfile(char const*& _buffer, SnsProfile& _result, std::optional<TalkException>& e);

            void postSnsInvitationMessage(char const*& _buffer, std::optional<TalkException>& e);

            void reportDeviceState(char const*& _buffer, std::optional<TalkException>& e);

            void notifySleepV2(char const*& _buffer, std::optional<TalkException>& e);

            void updateNotificationToken(char const*& _buffer, std::optional<TalkException>& e);

            void updateGroup(char const*& _buffer, std::optional<TalkException>& e);

            void verifyAccountMigrationPincode(char const*& _buffer, std::optional<TalkException>& e);

            void registerWithExistingSnsIdAndIdentityCredential(char const*& _buffer, std::string& _result, std::optional<TalkException>& e);

            void registerDeviceWithoutPhoneNumber(char const*& _buffer, std::string& _result, std::optional<TalkException>& e);

            void changeVerificationMethod(char const*& _buffer, VerificationSessionData& _result, std::optional<TalkException>& e);

            void setBuddyLocation(char const*& _buffer, std::optional<TalkException>& e);

            void getFriendRequests(char const*& _buffer, std::vector<FriendRequest>& _result, std::optional<TalkException>& e);

            void kickoutFromGroup(char const*& _buffer, std::optional<TalkException>& e);

            void verifyIdentityCredentialWithResult(char const*& _buffer, UserAuthStatus& _result, std::optional<TalkException>& e);

            void sendEchoPush(char const*& _buffer, std::optional<TalkException>& e);

            void createSession(char const*& _buffer, std::string& _result, std::optional<TalkException>& e);

            void reissueDeviceCredential(char const*& _buffer, std::string& _result, std::optional<TalkException>& e);

            void getRecommendationIds(char const*& _buffer, std::vector<std::string>& _result, std::optional<TalkException>& e);

            void inviteViaEmail(char const*& _buffer, std::optional<TalkException>& e);

            void getRoomsV2(char const*& _buffer, std::vector<Room>& _result, std::optional<TalkException>& e);

            void getReadMessageOps(char const*& _buffer, std::vector<Operation>& _result, std::optional<TalkException>& e);

            void getSettingsAttributes(char const*& _buffer, Settings& _result, std::optional<TalkException>& e);

            void requestIdentityUnbind(char const*& _buffer, std::optional<TalkException>& e);

            void getMessagesBySequenceNumber(char const*& _buffer, std::vector<Message>& _result, std::optional<TalkException>& e);

            void inviteIntoRoom(char const*& _buffer, std::optional<TalkException>& e);

            void sendChatChecked(char const*& _buffer, std::optional<TalkException>& e);

            void removeSnsId(char const*& _buffer, std::string& _result, std::optional<TalkException>& e);

            void reportSpammer(char const*& _buffer, std::optional<TalkException>& e);

            void findAndAddContactsByEmail(char const*& _buffer, std::map<std::string, Contact>& _result, std::optional<TalkException>& e);

            void getCompactGroups(char const*& _buffer, std::vector<Group>& _result, std::optional<TalkException>& e);

            void sendMessage(char const*& _buffer, Message& _result, std::optional<TalkException>& e);

            void getRooms(char const*& _buffer, std::vector<Room>& _result, std::optional<TalkException>& e);

            void updateC2DMRegistrationId(char const*& _buffer, std::optional<TalkException>& e);

            void sendPostback(char const*& _buffer, std::optional<TalkException>& e);

            void getReadMessageOpsInBulk(char const*& _buffer, std::vector<Operation>& _result, std::optional<TalkException>& e);

            void sendMessageIgnored(char const*& _buffer, std::optional<TalkException>& e);

            void getMessageBoxWrapUpListV2(char const*& _buffer, TMessageBoxWrapUpResponse& _result, std::optional<TalkException>& e);

            void getOldReadMessageOpsWithRange(char const*& _buffer, std::vector<Operation>& _result, std::optional<TalkException>& e);

            void getRSAKeyInfo(char const*& _buffer, RSAKey& _result, std::optional<TalkException>& e);

            void updateProfileAttribute(char const*& _buffer, std::optional<TalkException>& e);

            void createAccountMigrationPincodeSession(char const*& _buffer, std::string& _result, std::optional<TalkException>& e);

            void notifiedRedirect(char const*& _buffer, std::optional<TalkException>& e);

            void notifyIndividualEvent(char const*& _buffer, std::optional<TalkException>& e);

            void updateApnsDeviceToken(char const*& _buffer, std::optional<TalkException>& e);

            void getMessageBoxCompactWrapUpListV2(char const*& _buffer, TMessageBoxWrapUpResponse& _result, std::optional<TalkException>& e);

            void requestEmailConfirmation(char const*& _buffer, EmailConfirmationSession& _result, std::optional<TalkException>& e);

            void registerWithSnsIdAndIdentityCredential(char const*& _buffer, std::string& _result, std::optional<TalkException>& e);

            void getMessageBoxCompactWrapUp(char const*& _buffer, TMessageBoxWrapUp& _result, std::optional<TalkException>& e);

            void findContactByUserTicket(char const*& _buffer, Contact& _result, std::optional<TalkException>& e);

            void updateAccountMigrationPincode(char const*& _buffer, std::optional<TalkException>& e);

            void registerBuddyUser(char const*& _buffer, std::string& _result, std::optional<TalkException>& e);

            void updateSettingsV2(char const*& _buffer, uint32_t& _result, std::optional<TalkException>& e);

            void getUserTicket(char const*& _buffer, Ticket& _result, std::optional<TalkException>& e);

            void fetchOps(char const*& _buffer, std::vector<Operation>& _result, std::optional<ShouldSyncException>& e);

            void commitSendMessagesToMid(char const*& _buffer, CommitSendMessagesToMidResponse& _result, std::optional<TalkException>& e);

            void getMessageBoxV2(char const*& _buffer, TMessageBox& _result, std::optional<TalkException>& e);

            void requestResendMessage(char const*& _buffer, std::optional<TalkException>& e);

            void getGroupWithoutMembers(char const*& _buffer, Group& _result, std::optional<TalkException>& e);

            void removeAllMessages(char const*& _buffer, std::optional<TalkException>& e);

            void verifyAccountMigration(char const*& _buffer, std::optional<TalkException>& e);

            void reissueGroupTicket(char const*& _buffer, std::string& _result, std::optional<TalkException>& e);

            void logoutSession(char const*& _buffer, std::optional<TalkException>& e);

            void getBuddyLocation(char const*& _buffer, Geolocation& _result, std::optional<TalkException>& e);

            void getWapInvitation(char const*& _buffer, WapInvitation& _result, std::optional<TalkException>& e);

            void registerDevice(char const*& _buffer, std::string& _result, std::optional<TalkException>& e);

            void clearMessageBox(char const*& _buffer, std::optional<TalkException>& e);

            void loginWithIdentityCredentialForCertificate(char const*& _buffer, LoginResult& _result, std::optional<TalkException>& e);

            void getSuggestSettings(char const*& _buffer, SuggestDictionarySettings& _result, std::optional<TalkException>& e);

            void updateAndGetNearby(char const*& _buffer, std::vector<NearbyEntry>& _result, std::optional<TalkException>& e);

            void syncContactBySnsIds(char const*& _buffer, std::vector<SnsFriendContactRegistration>& _result, std::optional<TalkException>& e);

            void getContacts(char const*& _buffer, std::vector<Contact>& _result, std::optional<TalkException>& e);

            void getMessageBoxCompactWrapUpList(char const*& _buffer, TMessageBoxWrapUpResponse& _result, std::optional<TalkException>& e);

            void getProximityMatchCandidates(char const*& _buffer, std::set<Contact>& _result, std::optional<TalkException>& e);

            void updateExtendedProfileAttribute(char const*& _buffer, std::optional<TalkException>& e);

            void resendPinCode(char const*& _buffer, std::optional<TalkException>& e);

            void reportSettings(char const*& _buffer, std::optional<TalkException>& e);

            void registerBuddyUserid(char const*& _buffer, std::optional<TalkException>& e);

            void findGroupByTicket(char const*& _buffer, Group& _result, std::optional<TalkException>& e);

            void registerDeviceWithIdentityCredential(char const*& _buffer, std::string& _result, std::optional<TalkException>& e);

            void invalidateUserTicket(char const*& _buffer, std::optional<TalkException>& e);

            void sendEvent(char const*& _buffer, Message& _result, std::optional<TalkException>& e);

            void sendMessageToMyHome(char const*& _buffer, Message& _result, std::optional<TalkException>& e);

            void sendContentPreviewUpdated(char const*& _buffer, std::map<std::string, std::string>& _result, std::optional<TalkException>& e);

            void loginWithVerifier(char const*& _buffer, std::string& _result, std::optional<TalkException>& e);

            void removeBuddySubscriptionAndNotifyBuddyUnregistered(char const*& _buffer, std::optional<TalkException>& e);

            void unblockContact(char const*& _buffer, std::optional<TalkException>& e);

            void removeBuddyLocation(char const*& _buffer, std::optional<TalkException>& e);

            void getRingbackTone(char const*& _buffer, RingbackTone& _result, std::optional<TalkException>& e);

            void getConfigurations(char const*& _buffer, Configurations& _result, std::optional<TalkException>& e);

            void getProximityMatchCandidateList(char const*& _buffer, ProximityMatchCandidateResult& _result, std::optional<TalkException>& e);

            void requestAccountPasswordReset(char const*& _buffer, std::optional<TalkException>& e);

            void getNextMessages(char const*& _buffer, std::vector<Message>& _result, std::optional<TalkException>& e);

            void reportProfile(char const*& _buffer, std::optional<TalkException>& e);

            void getCompactRoom(char const*& _buffer, Room& _result, std::optional<TalkException>& e);

            void getLastOpRevision(char const*& _buffer, uint64_t& _result, std::optional<TalkException>& e);

            void getPreviousMessagesV2(char const*& _buffer, std::vector<Message>& _result, std::optional<TalkException>& e);

            void fetchAnnouncements(char const*& _buffer, std::vector<Announcement>& _result, std::optional<TalkException>& e);

            void acquireCallRoute(char const*& _buffer, std::vector<std::string>& _result, std::optional<TalkException>& e);

            void updateSettingsAttribute(char const*& _buffer, std::optional<TalkException>& e);

            void createGroupV2(char const*& _buffer, Group& _result, std::optional<TalkException>& e);

            void isIdentityIdentifierAvailable(char const*& _buffer, bool& _result, std::optional<TalkException>& e);

            void blockContact(char const*& _buffer, std::optional<TalkException>& e);

            void commitUpdateProfile(char const*& _buffer, std::map<std::string, std::string>& _result, std::optional<TalkException>& e);

            void registerWithSnsId(char const*& _buffer, RegisterWithSnsIdResult& _result, std::optional<TalkException>& e);

            void updatePublicKeychain(char const*& _buffer, PublicKeychain& _result, std::optional<TalkException>& e);

            void loginWithVerifierForCerificate(char const*& _buffer, LoginResult& _result, std::optional<TalkException>& e);

            void tryFriendRequest(char const*& _buffer, std::optional<TalkException>& e);

            void getBlockedRecommendationIds(char const*& _buffer, std::vector<std::string>& _result, std::optional<TalkException>& e);

            void getGroupIdsInvited(char const*& _buffer, std::vector<std::string>& _result, std::optional<TalkException>& e);

            void getSuggestIncrements(char const*& _buffer, SuggestDictionaryIncrements& _result, std::optional<TalkException>& e);

            void resendPinCodeBySMS(char const*& _buffer, std::optional<TalkException>& e);

            void registerWithPhoneNumber(char const*& _buffer, RegisterWithPhoneNumberResult& _result, std::optional<TalkException>& e);

            void getActiveBuddySubscriberIds(char const*& _buffer, std::vector<std::string>& _result, std::optional<TalkException>& e);

            void createRoom(char const*& _buffer, Room& _result, std::optional<TalkException>& e);

            void verifyPhoneNumberForLogin(char const*& _buffer, std::string& _result, std::optional<TalkException>& e);

            void addSnsId(char const*& _buffer, std::string& _result, std::optional<TalkException>& e);

            void finishUpdateVerification(char const*& _buffer, std::optional<TalkException>& e);

            void validateContactsOnBot(char const*& _buffer, std::map<std::string, std::string>& _result, std::optional<TalkException>& e);

            void getRoom(char const*& _buffer, Room& _result, std::optional<TalkException>& e);

            void closeProximityMatch(char const*& _buffer, std::optional<TalkException>& e);

            void getCompactGroup(char const*& _buffer, Group& _result, std::optional<TalkException>& e);

            void getBlockedContactIdsByRange(char const*& _buffer, std::vector<std::string>& _result, std::optional<TalkException>& e);

            void getRecentMessagesV2(char const*& _buffer, std::vector<Message>& _result, std::optional<TalkException>& e);

            void reissueUserTicket(char const*& _buffer, std::string& _result, std::optional<TalkException>& e);

            void getMessageReadRange(char const*& _buffer, std::vector<TMessageReadRange>& _result, std::optional<TalkException>& e);

            void clearRingbackTone(char const*& _buffer, std::optional<TalkException>& e);

            void setIdentityCredential(char const*& _buffer, std::optional<TalkException>& e);

            void getMessageBoxCompactWrapUpV2(char const*& _buffer, TMessageBoxWrapUp& _result, std::optional<TalkException>& e);

            void getServerTime(char const*& _buffer, uint64_t& _result, std::optional<TalkException>& e);

            void trySendMessage(char const*& _buffer, Message& _result, std::optional<TalkException>& e);

            void getNextMessagesV2(char const*& _buffer, std::vector<Message>& _result, std::optional<TalkException>& e);

            void notifySleep(char const*& _buffer, std::optional<TalkException>& e);

            void getBuddyBlockerIds(char const*& _buffer, std::vector<std::string>& _result, std::optional<TalkException>& e);

            void removeE2EEPublicKey(char const*& _buffer, std::optional<TalkException>& e);

            void reissueTrackingTicket(char const*& _buffer, std::string& _result, std::optional<TalkException>& e);

            void cancelGroupInvitation(char const*& _buffer, std::optional<TalkException>& e);

            void removeMessage(char const*& _buffer, bool& _result, std::optional<TalkException>& e);

            void getAllReadMessageOps(char const*& _buffer, std::vector<Operation>& _result, std::optional<TalkException>& e);

            void unregisterUserAndDevice(char const*& _buffer, std::string& _result, std::optional<TalkException>& e);

            void acceptGroupInvitation(char const*& _buffer, std::optional<TalkException>& e);

            void getCompactContactsModifiedSince(char const*& _buffer, std::vector<CompactContact>& _result, std::optional<TalkException>& e);

            void releaseSession(char const*& _buffer, std::optional<TalkException>& e);

            void findContactsByPhone(char const*& _buffer, std::map<std::string, Contact>& _result, std::optional<TalkException>& e);

            void getHiddenContactMids(char const*& _buffer, std::vector<std::string>& _result, std::optional<TalkException>& e);

            void getEncryptedIdentity(char const*& _buffer, std::string& _result, std::optional<TalkException>& e);

            void updateProfile(char const*& _buffer, std::optional<TalkException>& e);

            void reportSpam(char const*& _buffer, std::optional<TalkException>& e);

            void getSuggestRevisions(char const*& _buffer, SuggestDictionaryRevisions& _result, std::optional<TalkException>& e);

            void getPreviousMessagesV2WithReadCount(char const*& _buffer, std::vector<Message>& _result, std::optional<TalkException>& e);

            void fetchOperations(char const*& _buffer, std::vector<Operation>& _result, std::optional<ShouldSyncException>& e);

            void registerWapDevice(char const*& _buffer, std::string& _result, std::optional<TalkException>& e);

            void getRecentFriendRequests(char const*& _buffer, FriendRequestsInfo& _result, std::optional<TalkException>& e);

            void notifyBuddyOnAir(char const*& _buffer, std::map<std::string, std::string>& _result, std::optional<TalkException>& e);

            void getLastAnnouncementIndex(char const*& _buffer, uint32_t& _result, std::optional<TalkException>& e);

            void sendMessageAwaitCommit(char const*& _buffer, CommitMessageResult& _result, std::optional<TalkException>& e);

            void negotiateE2EEPublicKey(char const*& _buffer, E2EENegotiationResult& _result, std::optional<TalkException>& e);

            void registerE2EEGroupKey(char const*& _buffer, E2EEGroupSharedKey& _result, std::optional<TalkException>& e);

            void findSnsIdUserStatus(char const*& _buffer, SnsIdUserStatus& _result, std::optional<TalkException>& e);

            void notifyUpdated(char const*& _buffer, std::optional<TalkException>& e);

            void reportGroups(char const*& _buffer, std::optional<TalkException>& e);

            void getNotificationPolicy(char const*& _buffer, std::vector<NotificationType>& _result, std::optional<TalkException>& e);

            void findAndAddContactsByUserid(char const*& _buffer, std::map<std::string, Contact>& _result, std::optional<TalkException>& e);

            void getLastE2EEGroupSharedKey(char const*& _buffer, E2EEGroupSharedKey& _result, std::optional<TalkException>& e);

            void notifyUpdatePublicKeychain(char const*& _buffer, std::optional<TalkException>& e);

            void report(char const*& _buffer, std::optional<TalkException>& e);

            void acceptGroupInvitationByTicket(char const*& _buffer, std::optional<TalkException>& e);

            void getContactRegistration(char const*& _buffer, ContactRegistration& _result, std::optional<TalkException>& e);

            void updateContactSetting(char const*& _buffer, std::optional<TalkException>& e);

            void getContactWithFriendRequestStatus(char const*& _buffer, Contact& _result, std::optional<TalkException>& e);

            void getMessageBoxListByStatus(char const*& _buffer, std::vector<TMessageBox>& _result, std::optional<TalkException>& e);

            void openProximityMatch(char const*& _buffer, std::string& _result, std::optional<TalkException>& e);

            void logout(char const*& _buffer, std::optional<TalkException>& e);

            void getE2EEPublicKey(char const*& _buffer, E2EEPublicKey& _result, std::optional<TalkException>& e);

            void registerUserid(char const*& _buffer, bool& _result, std::optional<TalkException>& e);

            void reportContacts(char const*& _buffer, std::vector<ContactReportResult>& _result, std::optional<TalkException>& e);

            void getPublicKeychain(char const*& _buffer, PublicKeychain& _result, std::optional<TalkException>& e);

            void sendContentReceipt(char const*& _buffer, std::optional<TalkException>& e);

            void respondResendMessage(char const*& _buffer, std::optional<TalkException>& e);

            void getAllRoomIds(char const*& _buffer, std::set<std::string>& _result, std::optional<TalkException>& e);

            void requestE2EEKeyExchange(char const*& _buffer, std::optional<TalkException>& e);

            void disableNearby(char const*& _buffer, std::optional<TalkException>& e);

            void createQrcodeBase64Image(char const*& _buffer, std::string& _result, std::optional<TalkException>& e);

            void getMessageBoxList(char const*& _buffer, std::vector<TMessageBox>& _result, std::optional<TalkException>& e);

            void respondE2EEKeyExchange(char const*& _buffer, std::optional<TalkException>& e);

            void verifyQrcode(char const*& _buffer, std::string& _result, std::optional<TalkException>& e);

            void updateNotificationTokenWithBytes(char const*& _buffer, std::optional<TalkException>& e);

            void getPreviousMessages(char const*& _buffer, std::vector<Message>& _result, std::optional<TalkException>& e);

            void getSettings(char const*& _buffer, Settings& _result, std::optional<TalkException>& e);

            void getLastE2EEPublicKeys(char const*& _buffer, std::map<std::string, E2EEPublicKey>& _result, std::optional<TalkException>& e);

            void registerE2EEPublicKey(char const*& _buffer, E2EEPublicKey& _result, std::optional<TalkException>& e);

            void acquireCallTicket(char const*& _buffer, std::string& _result, std::optional<TalkException>& e);

            void inviteIntoGroup(char const*& _buffer, std::optional<TalkException>& e);

            void makeUserAddMyselfAsContact(char const*& _buffer, ContactTransition& _result, std::optional<TalkException>& e);

            void removeMessageFromMyHome(char const*& _buffer, bool& _result, std::optional<TalkException>& e);

            void commitSendMessages(char const*& _buffer, std::map<std::string, std::string>& _result, std::optional<TalkException>& e);

            void registerWithPhoneNumberAndPassword(char const*& _buffer, RegisterWithPhoneNumberResult& _result, std::optional<TalkException>& e);

            void leaveGroup(char const*& _buffer, std::optional<TalkException>& e);

            void getAnalyticsInfo(char const*& _buffer, AnalyticsInfo& _result, std::optional<TalkException>& e);

            void reportClientStatistics(char const*& _buffer, std::optional<TalkException>& e);

            void acceptProximityMatches(char const*& _buffer, std::optional<TalkException>& e);

            void getGroup(char const*& _buffer, Group& _result, std::optional<TalkException>& e);

            void clearIdentityCredential(char const*& _buffer, std::optional<TalkException>& e);

            void getUpdatedMessageBoxIds(char const*& _buffer, std::vector<std::string>& _result, std::optional<TalkException>& e);

            void getGroups(char const*& _buffer, std::vector<Group>& _result, std::optional<TalkException>& e);

            void sendMessageReceipt(char const*& _buffer, std::optional<TalkException>& e);

            void findContactByMetaTag(char const*& _buffer, Contact& _result, std::optional<TalkException>& e);

            void destroyMessage(char const*& _buffer, std::optional<TalkException>& e);

            void generateUserTicket(char const*& _buffer, Ticket& _result, std::optional<TalkException>& e);

            void registerDeviceWithoutPhoneNumberWithIdentityCredential(char const*& _buffer, std::string& _result, std::optional<TalkException>& e);

            void getFavoriteMids(char const*& _buffer, std::vector<std::string>& _result, std::optional<TalkException>& e);

            void getAcceptedProximityMatches(char const*& _buffer, std::set<std::string>& _result, std::optional<TalkException>& e);

            void notifyInstalled(char const*& _buffer);

            void getCountryWithRequestIp(char const*& _buffer, std::string& _result, std::optional<TalkException>& e);

            void getGroupsV2(char const*& _buffer, std::vector<Group>& _result, std::optional<TalkException>& e);

            void loginWithIdentityCredential(char const*& _buffer, std::string& _result, std::optional<TalkException>& e);

            void startUpdateVerification(char const*& _buffer, VerificationSessionData& _result, std::optional<TalkException>& e);

            void getSessions(char const*& _buffer, std::vector<LoginSession>& _result, std::optional<TalkException>& e);

            void updateSettings(char const*& _buffer, std::optional<TalkException>& e);

            void getContact(char const*& _buffer, Contact& _result, std::optional<TalkException>& e);

            void getBlockedContactIds(char const*& _buffer, std::vector<std::string>& _result, std::optional<TalkException>& e);

            void loginWithVerifierForCertificate(char const*& _buffer, LoginResult& _result, std::optional<TalkException>& e);

            void getProfile(char const*& _buffer, Profile& _result, std::optional<TalkException>& e);

            void findContactsByEmail(char const*& _buffer, std::map<std::string, Contact>& _result, std::optional<TalkException>& e);

            void getSystemConfiguration(char const*& _buffer, SystemConfiguration& _result, std::optional<TalkException>& e);

            void getRecentMessages(char const*& _buffer, std::vector<Message>& _result, std::optional<TalkException>& e);

            void verifyPhone(char const*& _buffer, VerificationResult& _result, std::optional<TalkException>& e);

            void createGroup(char const*& _buffer, Group& _result, std::optional<TalkException>& e);

            void updateBuddySetting(char const*& _buffer, std::optional<TalkException>& e);

            void updateRegion(char const*& _buffer, std::optional<TalkException>& e);

            void verifyIdentityCredential(char const*& _buffer, std::optional<TalkException>& e);

            void sendChatRemoved(char const*& _buffer, std::optional<TalkException>& e);

            void getGroupIdsJoined(char const*& _buffer, std::vector<std::string>& _result, std::optional<TalkException>& e);

            void findContactByUserid(char const*& _buffer, Contact& _result, std::optional<TalkException>& e);

            void getE2EEPublicKeys(char const*& _buffer, std::vector<E2EEPublicKey>& _result, std::optional<TalkException>& e);

            void getMessageBoxWrapUpList(char const*& _buffer, TMessageBoxWrapUpResponse& _result, std::optional<TalkException>& e);

            void leaveRoom(char const*& _buffer, std::optional<TalkException>& e);

            void unblockRecommendation(char const*& _buffer, std::optional<TalkException>& e);

            void findAndAddContactsByPhone(char const*& _buffer, std::map<std::string, Contact>& _result, std::optional<TalkException>& e);

            void getAuthQrcode(char const*& _buffer, AuthQrcode& _result, std::optional<TalkException>& e);

            void getE2EEGroupSharedKey(char const*& _buffer, E2EEGroupSharedKey& _result, std::optional<TalkException>& e);

            void getMessageBoxWrapUp(char const*& _buffer, TMessageBoxWrapUp& _result, std::optional<TalkException>& e);

            void updateSettingsAttributes(char const*& _buffer, uint32_t& _result, std::optional<TalkException>& e);

            void startVerification(char const*& _buffer, VerificationSessionData& _result, std::optional<TalkException>& e);

            void reportRooms(char const*& _buffer, std::optional<TalkException>& e);

            void updateGroupPreferenceAttribute(char const*& _buffer, std::optional<TalkException>& e);

            void getMessageBoxWrapUpV2(char const*& _buffer, TMessageBoxWrapUp& _result, std::optional<TalkException>& e);

            void getCompactRooms(char const*& _buffer, std::vector<Room>& _result, std::optional<TalkException>& e);

            void findAndAddContactByMetaTag(char const*& _buffer, Contact& _result, std::optional<TalkException>& e);

            void storeUpdateProfileAttribute(char const*& _buffer, std::optional<TalkException>& e);

            void resendEmailConfirmation(char const*& _buffer, EmailConfirmationSession& _result, std::optional<TalkException>& e);

            void confirmEmail(char const*& _buffer, EmailConfirmationResult& _result, std::optional<TalkException>& e);

            void getExtendedProfile(char const*& _buffer, ExtendedProfile& _result, std::optional<TalkException>& e);

            void isUseridAvailable(char const*& _buffer, bool& _result, std::optional<TalkException>& e);

            void notifyRegistrationComplete(char const*& _buffer, std::optional<TalkException>& e);

            void updateDeviceInfo(char const*& _buffer, std::optional<TalkException>& e);

            void blockRecommendation(char const*& _buffer, std::optional<TalkException>& e);

            void rejectGroupInvitation(char const*& _buffer, std::optional<TalkException>& e);

            void updateCustomModeSettings(char const*& _buffer, std::optional<TalkException>& e);

            void createRoomV2(char const*& _buffer, Room& _result, std::optional<TalkException>& e);

            void noop(char const*& _buffer, std::optional<TalkException>& e);

            void acquireEncryptedAccessToken(char const*& _buffer, std::string& _result, std::optional<TalkException>& e);

            void getE2EEPublicKeysEx(char const*& _buffer, std::vector<E2EEPublicKey>& _result, std::optional<TalkException>& e);

            void syncContacts(char const*& _buffer, std::map<std::string, ContactRegistration>& _result, std::optional<TalkException>& e);

            void findAndAddContactsByMid(char const*& _buffer, std::map<std::string, Contact>& _result, std::optional<TalkException>& e);

            void findGroupByTicketV2(char const*& _buffer, Group& _result, std::optional<TalkException>& e);

            void removeFriendRequest(char const*& _buffer, std::optional<TalkException>& e);

            void verifyPhoneNumber(char const*& _buffer, PhoneVerificationResult& _result, std::optional<TalkException>& e);

            void setNotificationsEnabled(char const*& _buffer, std::optional<TalkException>& e);

            void getAllContactIds(char const*& _buffer, std::vector<std::string>& _result, std::optional<TalkException>& e);

            void getIdentityIdentifier(char const*& _buffer, std::string& _result, std::optional<TalkException>& e);

            void sendDummyPush(char const*& _buffer, std::optional<TalkException>& e);

            void inviteFriendsBySms(char const*& _buffer, std::optional<TalkException>& e);

            void getMessageBox(char const*& _buffer, TMessageBox& _result, std::optional<TalkException>& e);

            void unsendMessage(char const*& _buffer, std::optional<TalkException>& e);

            void createChatRoomAnnouncement(char const*& _buffer, ChatRoomAnnouncement& _result, std::optional<TalkException>& e);

            void removeChatRoomAnnouncement(char const*& _buffer, std::optional<TalkException>& e);

            void getChatRoomAnnouncements(char const*& _buffer, std::vector<ChatRoomAnnouncement>& _result, std::optional<TalkException>& e);

            void getChatRoomAnnouncementsBulk(char const*& _buffer, std::vector<ChatRoomAnnouncement>& _result, std::optional<TalkException>& e);

            void unregisterBuddy(char const*& _buffer, std::optional<TalkException>& e);

            void sendBuddyContentMessageToMidsAsync(char const*& _buffer, std::string& _result, std::optional<TalkException>& e);

            void getAllBuddyMembers(char const*& _buffer, std::vector<std::string>& _result, std::optional<TalkException>& e);

            void getActiveMemberMidsByBuddyMid(char const*& _buffer, std::vector<std::string>& _result, std::optional<TalkException>& e);

            void updateBuddyProfileAttributes(char const*& _buffer, UpdateBuddyProfileResult& _result, std::optional<TalkException>& e);

            void storePrivateMessages(char const*& _buffer, MessageStoreResult& _result, std::optional<TalkException>& e);

            void updateBuddyProfileImageAsync(char const*& _buffer, std::string& _result, std::optional<TalkException>& e);

            void notifyBuddyBlocked(char const*& _buffer, std::optional<TalkException>& e);

            void getMemberCountByBuddyMid(char const*& _buffer, uint64_t& _result, std::optional<TalkException>& e);

            void isBuddyOnAirByMid(char const*& _buffer, bool& _result, std::optional<TalkException>& e);

            void commitPrivateMessages(char const*& _buffer, std::optional<TalkException>& e);

            void commitPublicMessagesToMids(char const*& _buffer, std::optional<TalkException>& e);

            void addBuddyMember(char const*& _buffer, std::optional<TalkException>& e);

            void linkAndSendBuddyContentMessageToMids(char const*& _buffer, SendBuddyMessageResult& _result, std::optional<TalkException>& e);

            void storeMessages(char const*& _buffer, std::vector<SendBuddyMessageResult>& _result, std::optional<TalkException>& e);

            void storeMessage(char const*& _buffer, SendBuddyMessageResult& _result, std::optional<TalkException>& e);

            void registerBuddy(char const*& _buffer, std::string& _result, std::optional<TalkException>& e);

            void getUnregisterBuddyResult(char const*& _buffer, UnregisterBuddyResult& _result, std::optional<TalkException>& e);

            void updateBuddySearchId(char const*& _buffer, std::optional<TalkException>& e);

            void uploadBuddyContent(char const*& _buffer, std::string& _result, std::optional<TalkException>& e);

            void updateBuddyProfileImage(char const*& _buffer, UpdateBuddyProfileResult& _result, std::optional<TalkException>& e);

            void sendBuddyMessageToAll(char const*& _buffer, SendBuddyMessageResult& _result, std::optional<TalkException>& e);

            void commitSendMessagesToAll(char const*& _buffer, SendBuddyMessageResult& _result, std::optional<TalkException>& e);

            void downloadMessageContent(char const*& _buffer, std::string& _result, std::optional<TalkException>& e);

            void updateBuddyProfileRichMenu(char const*& _buffer, UpdateBuddyProfileResult& _result, std::optional<TalkException>& e);

            void setBuddyOnAir(char const*& _buffer, SetBuddyOnAirResult& _result, std::optional<TalkException>& e);

            void unblockBuddyMember(char const*& _buffer, std::optional<TalkException>& e);

            void linkAndSendBuddyContentMessageToAll(char const*& _buffer, SendBuddyMessageResult& _result, std::optional<TalkException>& e);

            void removeBuddyMember(char const*& _buffer, std::optional<TalkException>& e);

            void commitSendMessagesToMidAsync(char const*& _buffer, std::string& _result, std::optional<TalkException>& e);

            void getUpdateBuddyProfileResult(char const*& _buffer, UpdateBuddyProfileResult& _result, std::optional<TalkException>& e);

            void notifyBuddyUnblocked(char const*& _buffer, std::optional<TalkException>& e);

            void updateBuddyProfileRichMenuAsync(char const*& _buffer, std::string& _result, std::optional<TalkException>& e);

            void getBuddyProfile(char const*& _buffer, BuddyProfile& _result, std::optional<TalkException>& e);

            void getBlockedBuddyMembers(char const*& _buffer, std::vector<std::string>& _result, std::optional<TalkException>& e);

            void commitPublicMessagesToAll(char const*& _buffer, std::optional<TalkException>& e);

            void linkAndSendBuddyContentMessageToAllAsync(char const*& _buffer, std::string& _result, std::optional<TalkException>& e);

            void sendBuddyContentMessageToAllAsync(char const*& _buffer, std::string& _result, std::optional<TalkException>& e);

            void getSetBuddyOnAirResult(char const*& _buffer, SetBuddyOnAirResult& _result, std::optional<TalkException>& e);

            void commitSendMessagesToMidsAsync(char const*& _buffer, std::string& _result, std::optional<TalkException>& e);

            void commitSendMessagesToStoredMidsAsync(char const*& _buffer, std::string& _result, std::optional<TalkException>& e);

            void updateBuddyAdminProfileAttribute(char const*& _buffer, std::optional<TalkException>& e);

            void setBuddyOnAirAsync(char const*& _buffer, std::string& _result, std::optional<TalkException>& e);

            void commitSendMessagesToMids(char const*& _buffer, SendBuddyMessageResult& _result, std::optional<TalkException>& e);

            void sendBuddyContentMessageToAll(char const*& _buffer, SendBuddyMessageResult& _result, std::optional<TalkException>& e);

            void updateBuddySettings(char const*& _buffer, std::optional<TalkException>& e);

            void notifyBuddySubscribed(char const*& _buffer, std::optional<TalkException>& e);

            void registerBuddyAdmin(char const*& _buffer, std::string& _result, std::optional<TalkException>& e);

            void getBlockerCountByBuddyMid(char const*& _buffer, uint64_t& _result, std::optional<TalkException>& e);

            void reissueContactTicket(char const*& _buffer, std::string& _result, std::optional<TalkException>& e);

            void validateContacts(char const*& _buffer, ValidateContactsResult& _result, std::optional<TalkException>& e);

            void sendBuddyMessageToMidsAsync(char const*& _buffer, std::string& _result, std::optional<TalkException>& e);

            void unregisterBuddyAsync(char const*& _buffer, std::optional<TalkException>& e);

            void getProfileImageUrlHash(char const*& _buffer, std::string& _result, std::optional<TalkException>& e);

            void blockBuddyMember(char const*& _buffer, std::optional<TalkException>& e);

            void sendIndividualEventToAllAsync(char const*& _buffer, std::optional<TalkException>& e);

            void deleteBotProfileImage(char const*& _buffer, std::optional<TalkException>& e);

            void sendBuddyContentMessageToMids(char const*& _buffer, SendBuddyMessageResult& _result, std::optional<TalkException>& e);

            void unregisterBuddyAdmin(char const*& _buffer, std::optional<TalkException>& e);

            void commitPublicMessagesToStoredMids(char const*& _buffer, std::optional<TalkException>& e);

            void removeBuddyMembers(char const*& _buffer, std::optional<TalkException>& e);

            void storePublicMessages(char const*& _buffer, MessageStoreResult& _result, std::optional<TalkException>& e);

            void addBuddyMembers(char const*& _buffer, std::optional<TalkException>& e);

            void getMessageCommitResult(char const*& _buffer, MessageCommitResult& _result, std::optional<TalkException>& e);

            void getBuddyDetailByMid(char const*& _buffer, BuddyDetail& _result, std::optional<TalkException>& e);

            void notifyBuddySubscriberUnregistered(char const*& _buffer, std::optional<TalkException>& e);

            void sendBuddyMessageToAllAsync(char const*& _buffer, std::string& _result, std::optional<TalkException>& e);

            void sendBuddyMessageToMids(char const*& _buffer, SendBuddyMessageResult& _result, std::optional<TalkException>& e);

            void commitSendMessagesToAllAsync(char const*& _buffer, std::string& _result, std::optional<TalkException>& e);

            void notifyBuddySubscriberEmpty(char const*& _buffer, std::optional<TalkException>& e);

            void updateBuddyAdminProfileImage(char const*& _buffer, std::optional<TalkException>& e);

            void updateBuddyProfileAttributesAsync(char const*& _buffer, std::string& _result, std::optional<TalkException>& e);

            void linkAndSendBuddyContentMessageToMidsAsync(char const*& _buffer, std::string& _result, std::optional<TalkException>& e);

            void downloadProfileImagePreview(char const*& _buffer, std::string& _result, std::optional<TalkException>& e);

            void downloadProfileImage(char const*& _buffer, std::string& _result, std::optional<TalkException>& e);

            void getSendBuddyMessageResult(char const*& _buffer, SendBuddyMessageResult& _result, std::optional<TalkException>& e);

            void containsBuddyMember(char const*& _buffer, bool& _result, std::optional<TalkException>& e);

            void getActiveMemberCountByBuddyMid(char const*& _buffer, uint64_t& _result, std::optional<TalkException>& e);

            void downloadMessageContentPreview(char const*& _buffer, std::string& _result, std::optional<TalkException>& e);

            void notifyBuddyRegistered(char const*& _buffer, std::optional<TalkException>& e);

            void lookupByPhoneNumber(char const*& _buffer, SpotPhoneNumberResponse& _result, std::optional<TalkException>& e);

            void lookupNearby(char const*& _buffer, SpotNearbyResponse& _result, std::optional<TalkException>& e);

            void checkUserAge(char const*& _buffer, UserAgeType& _result, std::optional<TalkException>& e);

            void checkUserAgeWithDocomo(char const*& _buffer, AgeCheckDocomoResult& _result, std::optional<TalkException>& e);

            void retrieveOpenIdAuthUrlWithDocomo(char const*& _buffer, std::string& _result, std::optional<TalkException>& e);

            void retrieveRequestToken(char const*& _buffer, AgeCheckRequestResult& _result, std::optional<TalkException>& e);

            void getBuddyStatusBar(char const*& _buffer, BuddyStatusBar& _result, std::optional<TalkException>& e);

            void getRichMenuContents(char const*& _buffer, BuddyRichMenuContents& _result, std::optional<TalkException>& e);

            void getBuddyProfilePopup(char const*& _buffer, BuddyProfilePopup& _result, std::optional<TalkException>& e);

            void getPopularBuddyBanner(char const*& _buffer, BuddyBanner& _result, std::optional<TalkException>& e);

            void getPopularBuddyLists(char const*& _buffer, std::vector<BuddyList>& _result, std::optional<TalkException>& e);

            void findBuddyContactsByQuery(char const*& _buffer, std::vector<BuddySearchResult>& _result, std::optional<TalkException>& e);

            void getBuddyNewsView(char const*& _buffer, BuddyNewsView& _result, std::optional<TalkException>& e);

            void getBuddyContacts(char const*& _buffer, std::vector<Contact>& _result, std::optional<TalkException>& e);

            void getBuddyCollectionEntries(char const*& _buffer, std::vector<BuddyCollectionEntry>& _result, std::optional<TalkException>& e);

            void getLatestBuddyNewsTimestamp(char const*& _buffer, uint64_t& _result, std::optional<TalkException>& e);

            void getBuddyChatBar(char const*& _buffer, BuddyChatBar& _result, std::optional<TalkException>& e);

            void getCountriesServingOfficialAccountPromotionV2(char const*& _buffer, std::set<std::string>& _result, std::optional<TalkException>& e);

            void getBuddyDetail(char const*& _buffer, BuddyDetail& _result, std::optional<TalkException>& e);

            void getBuddyOnAir(char const*& _buffer, BuddyOnAir& _result, std::optional<TalkException>& e);

            void getNewlyReleasedBuddyIds(char const*& _buffer, std::map<std::string, uint64_t>& _result, std::optional<TalkException>& e);

            void getBuddyCategoryView(char const*& _buffer, BuddyCategoryView& _result, std::optional<TalkException>& e);

            void getCountriesHavingBuddy(char const*& _buffer, std::vector<std::string>& _result, std::optional<TalkException>& e);

            void getPromotedBuddyContacts(char const*& _buffer, std::vector<Contact>& _result, std::optional<TalkException>& e);

            void getBuddyTopView(char const*& _buffer, BuddyTopView& _result, std::optional<TalkException>& e);

            void notifyLeaveGroup(char const*& _buffer, std::optional<TalkException>& e);

            void notifyLeaveRoom(char const*& _buffer, std::optional<TalkException>& e);

            void getBotUseInfo(char const*& _buffer, BotUseInfo& _result, std::optional<TalkException>& e);

            void sendChatCheckedByWatermark(char const*& _buffer, std::optional<TalkException>& e);

            void normalizePhoneNumber(char const*& _buffer, std::string& _result, std::optional<TalkException>& e);

            void respondE2EELoginRequest(char const*& _buffer, std::optional<TalkException>& e);

            void confirmE2EELogin(char const*& _buffer, std::string& _result, std::optional<TalkException>& e);

            void logoutZ(char const*& _buffer, std::optional<TalkException>& e);

            void loginZ(char const*& _buffer, LoginResult& _result, std::optional<TalkException>& e);

            void issueTokenForAccountMigrationSettings(char const*& _buffer, SecurityCenterResult& _result, std::optional<TalkException>& e);

            void issueTokenForAccountMigration(char const*& _buffer, SecurityCenterResult& _result, std::optional<TalkException>& e);

            void verifyQrcodeWithE2EE(char const*& _buffer, std::string& _result, std::optional<TalkException>& e);

        } // closing result namespace

    } // closing read namespace

    namespace write {

        namespace request {

            void getMoretabRecommend(std::string& _buffer);

            void requestBanPageForUser(std::string& _buffer);

            void requestBanPage(std::string& _buffer);

            void reserveCoinPurchase(std::string& _buffer, CoinPurchaseReservation& request);

            void getProductCategories(std::string& _buffer, std::string& language, std::string& country);

            void getProductList(std::string& _buffer, std::vector<std::string>& productIdList, std::string& language, std::string& country);

            void getCoinPurchaseHistory(std::string& _buffer, CoinHistoryCondition& request);

            void buyFreeProduct(std::string& _buffer, std::string& receiverMid, std::string& productId, uint32_t& messageTemplate, std::string& language, std::string& country, uint64_t& packageId);

            void getProductListWithCarrier(std::string& _buffer, std::vector<std::string>& productIdList, std::string& language, std::string& country, std::string& carrierCode);

            void getDefaultProducts(std::string& _buffer, std::string& language, std::string& country, std::string& carrierCode);

            void getProductsForCategory(std::string& _buffer, uint64_t& start, uint32_t& size, std::string& language, std::string& country, uint64_t& category);

            void notifyDownloaded(std::string& _buffer, uint64_t& packageId, std::string& language);

            void getFreePackagesWithoutEvent(std::string& _buffer, uint64_t& start, uint32_t& size, std::string& language, std::string& country);

            void getProduct(std::string& _buffer, uint64_t& packageID, std::string& language, std::string& country);

            void getEventPackages(std::string& _buffer, uint64_t& start, uint32_t& size, std::string& language, std::string& country);

            void getActivePurchaseVersions(std::string& _buffer, uint64_t& start, uint32_t& size, std::string& language, std::string& country);

            void getCoinProductsByPgCode(std::string& _buffer, PaymentType& appStoreCode, PaymentPgType& pgCode, std::string& country, std::string& language);

            void getNewlyReleasedPackages(std::string& _buffer, uint64_t& start, uint32_t& size, std::string& language, std::string& country);

            void getDownloads(std::string& _buffer, uint64_t& start, uint32_t& size, std::string& language, std::string& country);

            void getCoinProducts(std::string& _buffer, PaymentType& appStoreCode, std::string& country, std::string& language);

            void searchProducts(std::string& _buffer, uint64_t& start, uint32_t& size, std::string& language, std::string& country, std::string& query);

            void buyMustbuyProduct(std::string& _buffer, std::string& receiverMid, std::string& productId, uint32_t& messageTemplate, std::string& language, std::string& country, uint64_t& packageId, std::string& serialNumber);

            void getRecommendationsForProduct(std::string& _buffer, uint64_t& packageID, uint32_t& offset, uint32_t& limit, std::string& language, std::string& country);

            void getUpdates(std::string& _buffer, std::string& language, std::string& country, uint64_t& localVersion);

            void getActivePurchases(std::string& _buffer, uint64_t& start, uint32_t& size, std::string& language, std::string& country);

            void getProductWithCarrier(std::string& _buffer, uint64_t& packageID, std::string& language, std::string& country, std::string& carrierCode);

            void buyCoinProduct(std::string& _buffer, PaymentReservation& paymentReservation);

            void getPopularPackages(std::string& _buffer, uint64_t& start, uint32_t& size, std::string& language, std::string& country);

            void reservePayment(std::string& _buffer, PaymentReservation& paymentReservation);

            void getPresentsSent(std::string& _buffer, uint64_t& start, uint32_t& size, std::string& language, std::string& country);

            void checkCanReceivePresent(std::string& _buffer, std::string& recipientMid, uint64_t& packageId, std::string& language, std::string& country);

            void getFreePackages(std::string& _buffer, uint64_t& start, uint32_t& size, std::string& language, std::string& country);

            void getPurchaseHistory(std::string& _buffer, uint64_t& start, uint32_t& size, std::string& language, std::string& country);

            void getTotalBalance(std::string& _buffer, PaymentType& appStoreCode);

            void getCoinUseAndRefundHistory(std::string& _buffer, CoinHistoryCondition& request);

            void getPresentsReceived(std::string& _buffer, uint64_t& start, uint32_t& size, std::string& language, std::string& country);

            void getPlaceSearchInfo(std::string& _buffer, PlaceSearchProvider& provider, std::string& keyword, std::string& clientLocale, double& latitude, double& longitude, uint32_t& radius);

            void getUserStatus(std::string& _buffer, std::string& mid);

            void updateProfileAttributeForChannel(std::string& _buffer, ProfileAttribute& profileAttribute, std::string& value);

            void getAllSimpleChannelContacts(std::string& _buffer, bool& statusSticonFallbackDisabled);

            void getUserIdentities(std::string& _buffer);

            void markPaidCallAd(std::string& _buffer, std::string& dialedNumber, std::string& language, bool& disableCallerId);

            void isGroupMember(std::string& _buffer, std::string& groupId);

            void getPhoneInfoFromPhoneNumber(std::string& _buffer, std::string& region, std::string& phoneNumber);

            void redeemPaidCallVoucher(std::string& _buffer, std::string& serial, std::string& language);

            void getPreferredDisplayName(std::string& _buffer, std::vector<std::string>& mids);

            void getContactsForChannel(std::string& _buffer, std::vector<std::string>& ids);

            void getCallCreditProducts(std::string& _buffer, PaymentType& appStoreCode, PaymentPgType& pgCode, std::string& country, std::string& language);

            void getCompactContacts(std::string& _buffer, uint64_t& lastModifiedTimestamp);

            void notifyNotiCenterEvent(std::string& _buffer, NotiCenterEventData& event);

            void isInContact(std::string& _buffer, std::string& mid);

            void lookupGroupMembers(std::string& _buffer, std::string& groupId, std::vector<std::string>& mids);

            void getRoomInformation(std::string& _buffer, std::string& roomMid);

            void getGroupCall(std::string& _buffer, std::string& chatMid);

            void isAllowSecondaryDeviceLogin(std::string& _buffer);

            void getPrimaryClientForChannel(std::string& _buffer);

            void createRoomWithBuddy(std::string& _buffer, uint32_t& reqSeq, std::string& buddyMid, std::vector<std::string>& contactIds);

            void getDisplayName(std::string& _buffer, std::string& mid);

            void getPaidCallMetadata(std::string& _buffer, std::string& language);

            void getMid(std::string& _buffer);

            void getUserCountryForBilling(std::string& _buffer, std::string& country, std::string& remoteIp);

            void getFavoriteGroupIdsForChannel(std::string& _buffer);

            void getPaidCallHistory(std::string& _buffer, uint64_t& start, uint32_t& size, std::string& language);

            void sendPinCodeOperation(std::string& _buffer, std::string& verifier);

            void inviteIntoGroupCall(std::string& _buffer, std::string& chatMid, std::vector<std::string>& memberMids, GroupCallMediaType& mediaType);

            void getFriendMids(std::string& _buffer);

            void getMetaProfile(std::string& _buffer);

            void sendMessageForChannel(std::string& _buffer, Message& message);

            void activeBuddySubscriberCount(std::string& _buffer);

            void getCallCreditPurchaseHistory(std::string& _buffer, CoinHistoryCondition& request);

            void isRoomMember(std::string& _buffer, std::string& roomId);

            void sendSystemOAMessage(std::string& _buffer, Message& message);

            void acquirePaidCallRoute(std::string& _buffer, PaidCallType& paidCallType, std::string& dialedNumber, std::string& language, std::string& networkCode, bool& disableCallerId, std::string& referer, std::string& adSessionId);

            void getGroupsForChannel(std::string& _buffer, std::vector<std::string>& groupIds);

            void getUserCreateTime(std::string& _buffer);

            void registerChannelCP(std::string& _buffer, std::string& cpId, std::string& registerPassword);

            void reserveCallCreditPurchase(std::string& _buffer, CoinPurchaseReservation& request);

            void acquirePaidCallCurrencyExchangeRate(std::string& _buffer, std::string& language);

            void getRoomMemberMidsForAppPlatform(std::string& _buffer, std::string& roomId);

            void getPaidCallBalanceList(std::string& _buffer, std::string& language);

            void getPersonalInfos(std::string& _buffer, std::set<PersonalInfo>& requiredPersonalInfos);

            void getPrimaryClientsForChannel(std::string& _buffer, std::vector<std::string>& userMids);

            void addBuddyToContact(std::string& _buffer, std::string& buddyMid);

            void getGroupMemberMidsForAppPlatform(std::string& _buffer, std::string& groupId);

            void getUserLanguage(std::string& _buffer);

            void lookupPaidCall(std::string& _buffer, std::string& dialedNumber, std::string& language, std::string& referer);

            void getReverseCompactContacts(std::string& _buffer, std::vector<std::string>& ids);

            void getPaidCallAdStatus(std::string& _buffer);

            void findContactByUseridWithoutAbuseBlockForChannel(std::string& _buffer, std::string& userid);

            void getGroupMemberMids(std::string& _buffer, std::string& groupId);

            void sendMessageWithoutRelationship(std::string& _buffer, Message& message);

            void displayBuddySubscriberCountInBulk(std::string& _buffer, std::vector<std::string>& mids);

            void lookupRoomMembers(std::string& _buffer, std::string& roomId, std::vector<std::string>& mids);

            void getFavoriteMidsForChannel(std::string& _buffer);

            void getAllContactIdsForChannel(std::string& _buffer);

            void displayBuddySubscriberCount(std::string& _buffer);

            void getProfileForChannel(std::string& _buffer);

            void getUserTickets(std::string& _buffer, std::vector<std::string>& userMids);

            void getOAFriendMids(std::string& _buffer);

            void searchPaidCallUserRate(std::string& _buffer, std::string& countryCode, std::string& language);

            void getJoinedGroupIdsForChannel(std::string& _buffer);

            void acquireGroupCallRoute(std::string& _buffer, std::string& chatMid, GroupCallMediaType& mediaType);

            void getUserMidsWhoAddedMe(std::string& _buffer);

            void getIdentityCredential(std::string& _buffer);

            void addOperationForChannel(std::string& _buffer, OpType& opType, std::string& param1, std::string& param2, std::string& param3);

            void getSimpleChannelContacts(std::string& _buffer, std::vector<std::string>& ids, bool& statusSticonFallbackDisabled);

            void getUserLastSentMessageTimeStamp(std::string& _buffer, std::string& mid);

            void registerVirtualAccount(std::string& _buffer, std::string& locale, std::string& encryptedVirtualUserId, std::string& encryptedPassword);

            void unregisterVirtualAccount(std::string& _buffer, std::string& virtualMid);

            void requestVirtualAccountPasswordChange(std::string& _buffer, std::string& virtualMid, std::string& encryptedVirtualUserId, std::string& encryptedOldPassword, std::string& encryptedNewPassword);

            void notifyEmailConfirmationResult(std::string& _buffer, std::map<std::string, std::string>& parameterMap);

            void requestVirtualAccountPasswordSet(std::string& _buffer, std::string& virtualMid, std::string& encryptedVirtualUserId, std::string& encryptedNewPassword);

            void getRSAKey(std::string& _buffer);

            void queryBeaconActions(std::string& _buffer, std::string& hwid, std::string& secureMessage, ApplicationType& applicationType, std::string& applicationVersion, std::string& lang);

            void notifyBeaconDetected(std::string& _buffer, std::string& hwid, std::string& secureMessage, BeaconNotificationType& notificationType);

            void getDomains(std::string& _buffer, uint64_t& lastSynced);

            void approveChannelAndIssueRequestToken(std::string& _buffer, std::string& channelId, std::string& otpId);

            void issueOTP(std::string& _buffer, std::string& channelId);

            void getChannelSettings(std::string& _buffer);

            void getChannelNotificationSettings(std::string& _buffer, std::string& locale);

            void updateChannelNotificationSetting(std::string& _buffer, std::vector<ChannelNotificationSetting>& setting);

            void updateChannelSettings(std::string& _buffer, ChannelSettings& channelSettings);

            void getCommonDomains(std::string& _buffer, uint64_t& lastSynced);

            void issueRequestTokenWithAuthScheme(std::string& _buffer, std::string& channelId, std::string& otpId, std::vector<std::string>& authScheme, std::string& returnUrl);

            void getChannelNotificationSetting(std::string& _buffer, std::string& channelId, std::string& locale);

            void issueChannelToken(std::string& _buffer, std::string& channelId);

            void getChannels(std::string& _buffer, uint64_t& lastSynced, std::string& locale);

            void fetchNotificationItems(std::string& _buffer, uint64_t& localRev);

            void getChannelInfo(std::string& _buffer, std::string& channelId, std::string& locale);

            void getNotificationBadgeCount(std::string& _buffer, uint64_t& localRev);

            void issueRequestToken(std::string& _buffer, std::string& channelId, std::string& otpId);

            void revokeChannel(std::string& _buffer, std::string& channelId);

            void getApprovedChannels(std::string& _buffer, uint64_t& lastSynced, std::string& locale);

            void getFriendChannelMatrices(std::string& _buffer, std::vector<std::string>& channelIds);

            void issueRequestTokenForAutoLogin(std::string& _buffer, std::string& channelId, std::string& otpId, std::string& redirectUrl);

            void getUpdatedChannelIds(std::string& _buffer, std::vector<ChannelIdWithLastUpdated>& channelIds);

            void reserveCoinUse(std::string& _buffer, CoinUseReservation& request, std::string& locale);

            void syncChannelData(std::string& _buffer, uint64_t& lastSynced, std::string& locale);

            void approveChannelAndIssueChannelToken(std::string& _buffer, std::string& channelId);

            void getSnsFriends(std::string& _buffer, SnsIdType& snsIdType, std::string& snsAccessToken, uint32_t& startIdx, uint32_t& limit);

            void getSnsMyProfile(std::string& _buffer, SnsIdType& snsIdType, std::string& snsAccessToken);

            void postSnsInvitationMessage(std::string& _buffer, SnsIdType& snsIdType, std::string& snsAccessToken, std::string& toSnsUserId);

            void reportDeviceState(std::string& _buffer, std::map<DeviceBooleanStateKey, bool>& booleanState, std::map<DeviceStringStateKey, std::string>& stringState);

            void notifySleepV2(std::string& _buffer, std::map<ServiceCode, ClientLastStatus>& lastStatusMap);

            void updateNotificationToken(std::string& _buffer, std::string& token, NotificationType& type);

            void updateGroup(std::string& _buffer, uint32_t& reqSeq, Group& group);

            void verifyAccountMigrationPincode(std::string& _buffer, std::string& migrationPincodeSessionId, std::string& accountMigrationPincode);

            void registerWithExistingSnsIdAndIdentityCredential(std::string& _buffer, IdentityCredential& identityCredential, std::string& region, std::string& udidHash, DeviceInfo& deviceInfo, std::string& migrationPincodeSessionId);

            void registerDeviceWithoutPhoneNumber(std::string& _buffer, std::string& region, std::string& udidHash, DeviceInfo& deviceInfo);

            void changeVerificationMethod(std::string& _buffer, std::string& sessionId, VerificationMethod& method);

            void setBuddyLocation(std::string& _buffer, std::string& mid, uint32_t& index, Geolocation& location);

            void getFriendRequests(std::string& _buffer, FriendRequestDirection& direction, uint64_t& lastSeenSeqId);

            void kickoutFromGroup(std::string& _buffer, uint32_t& reqSeq, std::string& groupId, std::vector<std::string>& contactIds);

            void verifyIdentityCredentialWithResult(std::string& _buffer, IdentityCredential& identityCredential, std::string& migrationPincodeSessionId);

            void sendEchoPush(std::string& _buffer, std::string& text);

            void createSession(std::string& _buffer);

            void reissueDeviceCredential(std::string& _buffer);

            void getRecommendationIds(std::string& _buffer);

            void inviteViaEmail(std::string& _buffer, uint32_t& reqSeq, std::string& email, std::string& name);

            void getRoomsV2(std::string& _buffer, std::vector<std::string>& roomIds);

            void getReadMessageOps(std::string& _buffer, std::string& chatId);

            void getSettingsAttributes(std::string& _buffer, uint32_t& attrBitset);

            void requestIdentityUnbind(std::string& _buffer, std::string& identifier, IdentityProvider& provider);

            void getMessagesBySequenceNumber(std::string& _buffer, std::string& channelId, std::string& messageBoxId, uint64_t& startSeq, uint64_t& endSeq);

            void inviteIntoRoom(std::string& _buffer, uint32_t& reqSeq, std::string& roomId, std::vector<std::string>& contactIds);

            void sendChatChecked(std::string& _buffer, uint32_t& seq, std::string& consumer, std::string& lastMessageId, uint32_t& sessionId);

            void removeSnsId(std::string& _buffer, SnsIdType& snsIdType);

            void reportSpammer(std::string& _buffer, std::string& spammerMid, std::vector<SpammerReason>& spammerReasons, std::vector<std::string>& spamMessageIds, std::vector<std::string>& spamMessages);

            void findAndAddContactsByEmail(std::string& _buffer, uint32_t& reqSeq, std::set<std::string>& emails);

            void getCompactGroups(std::string& _buffer, std::vector<std::string>& groupIds);

            void sendMessage(std::string& _buffer, uint32_t& seq, Message& message);

            void getRooms(std::string& _buffer, std::vector<std::string>& roomIds);

            void updateC2DMRegistrationId(std::string& _buffer, std::string& registrationId);

            void sendPostback(std::string& _buffer, SendPostbackRequest& request);

            void getReadMessageOpsInBulk(std::string& _buffer, std::vector<std::string>& chatIds);

            void sendMessageIgnored(std::string& _buffer, uint32_t& seq, std::string& consumer, std::vector<std::string>& messageIds);

            void getMessageBoxWrapUpListV2(std::string& _buffer, uint32_t& messageBoxOffset, uint32_t& messageBoxCount);

            void getOldReadMessageOpsWithRange(std::string& _buffer, uint64_t& startRev, uint64_t& endRev);

            void getRSAKeyInfo(std::string& _buffer, IdentityProvider& provider);

            void updateProfileAttribute(std::string& _buffer, uint32_t& reqSeq, ProfileAttribute& attr, std::string& value);

            void createAccountMigrationPincodeSession(std::string& _buffer);

            void notifiedRedirect(std::string& _buffer, std::map<std::string, std::string>& paramMap);

            void notifyIndividualEvent(std::string& _buffer, NotificationStatus& notificationStatus, std::vector<std::string>& receiverMids);

            void updateApnsDeviceToken(std::string& _buffer, std::string& apnsDeviceToken);

            void getMessageBoxCompactWrapUpListV2(std::string& _buffer, uint32_t& messageBoxOffset, uint32_t& messageBoxCount);

            void requestEmailConfirmation(std::string& _buffer, EmailConfirmation& emailConfirmation);

            void registerWithSnsIdAndIdentityCredential(std::string& _buffer, SnsIdType& snsIdType, std::string& snsAccessToken, IdentityCredential& identityCredential, std::string& region, std::string& udidHash, DeviceInfo& deviceInfo, std::string& migrationPincodeSessionId);

            void getMessageBoxCompactWrapUp(std::string& _buffer, std::string& mid);

            void findContactByUserTicket(std::string& _buffer, std::string& ticketIdWithTag);

            void updateAccountMigrationPincode(std::string& _buffer, std::string& accountMigrationPincode);

            void registerBuddyUser(std::string& _buffer, std::string& buddyId, std::string& registrarPassword);

            void updateSettingsV2(std::string& _buffer, uint32_t& reqSeq, Settings& settings);

            void getUserTicket(std::string& _buffer);

            void fetchOps(std::string& _buffer, uint64_t& localRev, uint32_t& count, uint64_t& globalRev, uint64_t& individualRev);

            void commitSendMessagesToMid(std::string& _buffer, CommitSendMessagesToMidRequest& request);

            void getMessageBoxV2(std::string& _buffer, std::string& messageBoxId, uint32_t& lastMessagesCount);

            void requestResendMessage(std::string& _buffer, uint32_t& reqSeq, std::string& senderMid, std::string& messageId);

            void getGroupWithoutMembers(std::string& _buffer, std::string& groupId);

            void removeAllMessages(std::string& _buffer, uint32_t& seq, std::string& lastMessageId);

            void verifyAccountMigration(std::string& _buffer, std::string& migrationSessionId);

            void reissueGroupTicket(std::string& _buffer, std::string& groupMid);

            void logoutSession(std::string& _buffer, std::string& tokenKey);

            void getBuddyLocation(std::string& _buffer, std::string& mid, uint32_t& index);

            void getWapInvitation(std::string& _buffer, std::string& invitationHash);

            void registerDevice(std::string& _buffer, std::string& sessionId, std::string& migrationPincodeSessionId);

            void clearMessageBox(std::string& _buffer, std::string& channelId, std::string& messageBoxId);

            void loginWithIdentityCredentialForCertificate(std::string& _buffer, std::string& identifier, std::string& password, bool& keepLoggedIn, std::string& accessLocation, std::string& systemName, IdentityProvider& identityProvider, std::string& certificate);

            void getSuggestSettings(std::string& _buffer, std::string& locale);

            void updateAndGetNearby(std::string& _buffer, double& latitude, double& longitude);

            void syncContactBySnsIds(std::string& _buffer, uint32_t& reqSeq, std::vector<SnsFriendModification>& modifications);

            void getContacts(std::string& _buffer, std::vector<std::string>& ids);

            void getMessageBoxCompactWrapUpList(std::string& _buffer, uint32_t& start, uint32_t& messageBoxCount);

            void getProximityMatchCandidates(std::string& _buffer, std::string& sessionId);

            void updateExtendedProfileAttribute(std::string& _buffer, uint32_t& reqSeq, ExtendedProfileAttribute& attr, ExtendedProfile& extendedProfile);

            void resendPinCode(std::string& _buffer, std::string& sessionId);

            void reportSettings(std::string& _buffer, uint64_t& syncOpRevision, Settings& settings);

            void registerBuddyUserid(std::string& _buffer, uint32_t& seq, std::string& userid);

            void findGroupByTicket(std::string& _buffer, std::string& ticketId);

            void registerDeviceWithIdentityCredential(std::string& _buffer, std::string& sessionId, std::string& identifier, std::string& verifier, IdentityProvider& provider, std::string& migrationPincodeSessionId);

            void invalidateUserTicket(std::string& _buffer);

            void sendEvent(std::string& _buffer, uint32_t& seq, Message& message);

            void sendMessageToMyHome(std::string& _buffer, uint32_t& seq, Message& message);

            void sendContentPreviewUpdated(std::string& _buffer, uint32_t& esq, std::string& messageId, std::vector<std::string>& receiverMids);

            void loginWithVerifier(std::string& _buffer, std::string& verifier);

            void removeBuddySubscriptionAndNotifyBuddyUnregistered(std::string& _buffer, std::vector<std::string>& subscriberMids);

            void unblockContact(std::string& _buffer, uint32_t& reqSeq, std::string& id, std::string& reference);

            void removeBuddyLocation(std::string& _buffer, std::string& mid, uint32_t& index);

            void getRingbackTone(std::string& _buffer);

            void getConfigurations(std::string& _buffer, uint64_t& revision, std::string& regionOfUsim, std::string& regionOfTelephone, std::string& regionOfLocale, std::string& carrier);

            void getProximityMatchCandidateList(std::string& _buffer, std::string& sessionId);

            void requestAccountPasswordReset(std::string& _buffer, std::string& identifier, IdentityProvider& provider, std::string& locale);

            void getNextMessages(std::string& _buffer, std::string& messageBoxId, uint64_t& startSeq, uint32_t& messagesCount);

            void reportProfile(std::string& _buffer, uint64_t& syncOpRevision, Profile& profile);

            void getCompactRoom(std::string& _buffer, std::string& roomId);

            void getLastOpRevision(std::string& _buffer);

            void getPreviousMessagesV2(std::string& _buffer, std::string& messageBoxId, MessageBoxV2MessageId& endMessageId, uint32_t& messagesCount);

            void fetchAnnouncements(std::string& _buffer, uint32_t& lastFetchedIndex);

            void acquireCallRoute(std::string& _buffer, std::string& to);

            void updateSettingsAttribute(std::string& _buffer, uint32_t& reqSeq, SettingsAttribute& attr, std::string& value);

            void createGroupV2(std::string& _buffer, uint32_t& seq, std::string& name, std::vector<std::string>& contactIds);

            void isIdentityIdentifierAvailable(std::string& _buffer, std::string& identifier, IdentityProvider& provider);

            void blockContact(std::string& _buffer, uint32_t& reqSeq, std::string& id);

            void commitUpdateProfile(std::string& _buffer, uint32_t& seq, std::vector<ProfileAttribute>& attrs, std::vector<std::string>& receiverMids);

            void registerWithSnsId(std::string& _buffer, SnsIdType& snsIdType, std::string& snsAccessToken, std::string& region, std::string& udidHash, DeviceInfo& deviceInfo, std::string& mid, std::string& migrationPincodeSessionId);

            void updatePublicKeychain(std::string& _buffer, PublicKeychain& publicKeychain);

            void loginWithVerifierForCerificate(std::string& _buffer, std::string& verifier);

            void tryFriendRequest(std::string& _buffer, std::string& midOrEMid, FriendRequestMethod& method, std::string& friendRequestParams);

            void getBlockedRecommendationIds(std::string& _buffer);

            void getGroupIdsInvited(std::string& _buffer);

            void getSuggestIncrements(std::string& _buffer, SuggestDictionaryRevisions& revisions);

            void resendPinCodeBySMS(std::string& _buffer, std::string& sessionId);

            void registerWithPhoneNumber(std::string& _buffer, std::string& sessionId, std::string& migrationPincodeSessionId);

            void getActiveBuddySubscriberIds(std::string& _buffer);

            void createRoom(std::string& _buffer, uint32_t& reqSeq, std::vector<std::string>& contactIds);

            void verifyPhoneNumberForLogin(std::string& _buffer, std::string& verifierFromPhone, std::string& pinCodeForPhone, std::string& verifierFromLogin);

            void addSnsId(std::string& _buffer, SnsIdType& snsIdType, std::string& snsAccessToken);

            void finishUpdateVerification(std::string& _buffer, std::string& sessionId);

            void validateContactsOnBot(std::string& _buffer, std::vector<std::string>& contacts);

            void getRoom(std::string& _buffer, std::string& roomId);

            void closeProximityMatch(std::string& _buffer, std::string& sessionId);

            void getCompactGroup(std::string& _buffer, std::string& groupId);

            void getBlockedContactIdsByRange(std::string& _buffer, uint32_t& start, uint32_t& count);

            void getRecentMessagesV2(std::string& _buffer, std::string& messageBoxId, uint32_t& messagesCount);

            void reissueUserTicket(std::string& _buffer, uint64_t& expirationTime, uint32_t& maxUseCount);

            void getMessageReadRange(std::string& _buffer, std::vector<std::string>& chatIds);

            void clearRingbackTone(std::string& _buffer);

            void setIdentityCredential(std::string& _buffer, std::string& identifier, std::string& verifier, IdentityProvider& provider);

            void getMessageBoxCompactWrapUpV2(std::string& _buffer, std::string& messageBoxId);

            void getServerTime(std::string& _buffer);

            void trySendMessage(std::string& _buffer, uint32_t& seq, Message& message);

            void getNextMessagesV2(std::string& _buffer, std::string& messageBoxId, MessageBoxV2MessageId& startMessageId, uint32_t& messagesCount);

            void notifySleep(std::string& _buffer, uint64_t& lastRev, uint32_t& badge);

            void getBuddyBlockerIds(std::string& _buffer);

            void removeE2EEPublicKey(std::string& _buffer, E2EEPublicKey& publicKey);

            void reissueTrackingTicket(std::string& _buffer, TrackingType& type);

            void cancelGroupInvitation(std::string& _buffer, uint32_t& reqSeq, std::string& groupId, std::vector<std::string>& contactIds);

            void removeMessage(std::string& _buffer, std::string& messageId);

            void getAllReadMessageOps(std::string& _buffer);

            void unregisterUserAndDevice(std::string& _buffer);

            void acceptGroupInvitation(std::string& _buffer, uint32_t& reqSeq, std::string& groupId);

            void getCompactContactsModifiedSince(std::string& _buffer, uint64_t& timestamp);

            void releaseSession(std::string& _buffer);

            void findContactsByPhone(std::string& _buffer, std::set<std::string>& phones);

            void getHiddenContactMids(std::string& _buffer);

            void getEncryptedIdentity(std::string& _buffer);

            void updateProfile(std::string& _buffer, uint32_t& reqSeq, Profile& profile);

            void reportSpam(std::string& _buffer, std::string& chatMid, std::vector<std::string>& memberMids, std::vector<SpammerReason>& spammerReasons, std::vector<std::string>& senderMids, std::vector<std::string>& spamMessageIds, std::vector<std::string>& spamMessages);

            void getSuggestRevisions(std::string& _buffer);

            void getPreviousMessagesV2WithReadCount(std::string& _buffer, std::string& messageBoxId, MessageBoxV2MessageId& endMessageId, uint32_t& messagesCount);

            void fetchOperations(std::string& _buffer, uint64_t& localRev, uint32_t& count);

            void registerWapDevice(std::string& _buffer, std::string& invitationHash, std::string& guidHash, std::string& email, DeviceInfo& deviceInfo);

            void getRecentFriendRequests(std::string& _buffer);

            void notifyBuddyOnAir(std::string& _buffer, uint32_t& seq, std::vector<std::string>& receiverMids);

            void getLastAnnouncementIndex(std::string& _buffer);

            void sendMessageAwaitCommit(std::string& _buffer, uint32_t& seq, Message& message);

            void negotiateE2EEPublicKey(std::string& _buffer, std::string& mid);

            void registerE2EEGroupKey(std::string& _buffer, uint32_t& version, std::string& chatMid, std::vector<std::string>& members, std::vector<uint32_t>& keyIds, std::vector<std::string>& encryptedSharedKeys);

            void findSnsIdUserStatus(std::string& _buffer, SnsIdType& snsIdType, std::string& snsAccessToken, std::string& udidHash, std::string& migrationPincodeSessionId, std::string& oldUdidHash);

            void notifyUpdated(std::string& _buffer, uint64_t& lastRev, DeviceInfo& deviceInfo, std::string& udidHash, std::string& oldUdidHash);

            void reportGroups(std::string& _buffer, uint64_t& syncOpRevision, std::vector<Group>& groups);

            void getNotificationPolicy(std::string& _buffer, CarrierCode& carrier);

            void findAndAddContactsByUserid(std::string& _buffer, uint32_t& reqSeq, std::set<std::string>& userids);

            void getLastE2EEGroupSharedKey(std::string& _buffer, uint32_t& version, std::string& chatMid);

            void notifyUpdatePublicKeychain(std::string& _buffer, std::string& mid);

            void report(std::string& _buffer, uint64_t& syncOpRevision, SyncCategory& category, std::string& report);

            void acceptGroupInvitationByTicket(std::string& _buffer, uint32_t& reqSeq, std::string& groupMid, std::string& ticketId);

            void getContactRegistration(std::string& _buffer, std::string& id, ContactType& type);

            void updateContactSetting(std::string& _buffer, uint32_t& reqSeq, std::string& mid, ContactSetting& flag, std::string& value);

            void getContactWithFriendRequestStatus(std::string& _buffer, std::string& id);

            void getMessageBoxListByStatus(std::string& _buffer, std::string& channelId, uint32_t& lastMessagesCount, uint32_t& status);

            void openProximityMatch(std::string& _buffer, Location& location);

            void logout(std::string& _buffer);

            void getE2EEPublicKey(std::string& _buffer, std::string& mid, uint32_t& version, uint32_t& keyId);

            void registerUserid(std::string& _buffer, uint32_t& reqSeq, std::string& userid);

            void reportContacts(std::string& _buffer, uint64_t& syncOpRevision, SyncCategory& category, std::vector<ContactReport>& contactReports, SyncActionType& actionType);

            void getPublicKeychain(std::string& _buffer, std::string& mid);

            void sendContentReceipt(std::string& _buffer, uint32_t& seq, std::string& consumer, std::string& messageId);

            void respondResendMessage(std::string& _buffer, uint32_t& reqSeq, std::string& receiverMid, std::string& originalMessageId, Message& resendMessage, ErrorCode& errorCode);

            void getAllRoomIds(std::string& _buffer);

            void requestE2EEKeyExchange(std::string& _buffer, uint32_t& reqSeq, std::string& temporalPublicKey, E2EEPublicKey& publicKey, std::string& verifier);

            void disableNearby(std::string& _buffer);

            void createQrcodeBase64Image(std::string& _buffer, std::string& url, std::string& characterSet, uint32_t& imageSize, uint32_t& x, uint32_t& y, uint32_t& width, uint32_t& height);

            void getMessageBoxList(std::string& _buffer, std::string& channelId, uint32_t& lastMessagesCount);

            void respondE2EEKeyExchange(std::string& _buffer, uint32_t& reqSeq, std::string& encryptedKeyChain, std::string& hashKeyChain);

            void verifyQrcode(std::string& _buffer, std::string& verifier, std::string& pinCode);

            void updateNotificationTokenWithBytes(std::string& _buffer, std::string& token, NotificationType& type);

            void getPreviousMessages(std::string& _buffer, std::string& messageBoxId, uint64_t& endSeq, uint32_t& messagesCount);

            void getSettings(std::string& _buffer);

            void getLastE2EEPublicKeys(std::string& _buffer, std::string& chatMid);

            void registerE2EEPublicKey(std::string& _buffer, uint32_t& reqSeq, E2EEPublicKey& publicKey);

            void acquireCallTicket(std::string& _buffer, std::string& to);

            void inviteIntoGroup(std::string& _buffer, uint32_t& reqSeq, std::string& groupId, std::vector<std::string>& contactIds);

            void makeUserAddMyselfAsContact(std::string& _buffer, std::string& contactOwnerMid);

            void removeMessageFromMyHome(std::string& _buffer, std::string& messageId);

            void commitSendMessages(std::string& _buffer, uint32_t& seq, std::vector<std::string>& messageIds, std::vector<std::string>& receiverMids, bool& onlyToFollowers);

            void registerWithPhoneNumberAndPassword(std::string& _buffer, std::string& sessionId, std::string& keynm, std::string& encrypted);

            void leaveGroup(std::string& _buffer, uint32_t& reqSeq, std::string& groupId);

            void getAnalyticsInfo(std::string& _buffer);

            void reportClientStatistics(std::string& _buffer, uint32_t& reqSeq, ReportCategory& category, uint32_t& count);

            void acceptProximityMatches(std::string& _buffer, std::string& sessionId, std::set<std::string>& ids);

            void getGroup(std::string& _buffer, std::string& groupId);

            void clearIdentityCredential(std::string& _buffer);

            void getUpdatedMessageBoxIds(std::string& _buffer, MessageBoxV2MessageId& startMessageId, std::string& startMessageBoxId, uint32_t& messageBoxCount);

            void getGroups(std::string& _buffer, std::vector<std::string>& groupIds);

            void sendMessageReceipt(std::string& _buffer, uint32_t& seq, std::string& consumer, std::vector<std::string>& messageIds);

            void findContactByMetaTag(std::string& _buffer, std::string& userid, std::string& reference);

            void destroyMessage(std::string& _buffer, uint32_t& seq, std::string& chatId, std::string& messageId, uint32_t& sessionId);

            void generateUserTicket(std::string& _buffer, uint64_t& expirationTime, uint32_t& maxUseCount);

            void registerDeviceWithoutPhoneNumberWithIdentityCredential(std::string& _buffer, std::string& region, std::string& udidHash, DeviceInfo& deviceInfo, IdentityProvider& provider, std::string& identifier, std::string& verifier, std::string& mid, std::string& migrationPincodeSessionId);

            void getFavoriteMids(std::string& _buffer);

            void getAcceptedProximityMatches(std::string& _buffer, std::string& sessionId);

            void notifyInstalled(std::string& _buffer, std::string& udidHash, std::string& applicationTypeWithExtensions);

            void getCountryWithRequestIp(std::string& _buffer);

            void getGroupsV2(std::string& _buffer, std::vector<std::string>& groupIds);

            void loginWithIdentityCredential(std::string& _buffer, std::string& identifier, std::string& password, bool& keepLoggedIn, std::string& accessLocation, std::string& systemName, IdentityProvider& identityProvider, std::string& certificate);

            void startUpdateVerification(std::string& _buffer, std::string& region, CarrierCode& carrier, std::string& phone, std::string& udidHash, DeviceInfo& deviceInfo, std::string& networkCode, std::string& locale, SIMInfo& simInfo);

            void getSessions(std::string& _buffer);

            void updateSettings(std::string& _buffer, uint32_t& reqSeq, Settings& settings);

            void getContact(std::string& _buffer, std::string& id);

            void getBlockedContactIds(std::string& _buffer);

            void loginWithVerifierForCertificate(std::string& _buffer, std::string& verifier);

            void getProfile(std::string& _buffer);

            void findContactsByEmail(std::string& _buffer, std::set<std::string>& emails);

            void getSystemConfiguration(std::string& _buffer);

            void getRecentMessages(std::string& _buffer, std::string& messageBoxId, uint32_t& messagesCount);

            void verifyPhone(std::string& _buffer, std::string& sessionId, std::string& pinCode, std::string& udidHash);

            void createGroup(std::string& _buffer, uint32_t& seq, std::string& name, std::vector<std::string>& contactIds);

            void updateBuddySetting(std::string& _buffer, std::string& key, std::string& value);

            void updateRegion(std::string& _buffer, std::string& region);

            void verifyIdentityCredential(std::string& _buffer, std::string& identifier, std::string& password, IdentityProvider& identityProvider);

            void sendChatRemoved(std::string& _buffer, uint32_t& seq, std::string& consumer, std::string& lastMessageId, uint32_t& sessionId);

            void getGroupIdsJoined(std::string& _buffer);

            void findContactByUserid(std::string& _buffer, std::string& userid);

            void getE2EEPublicKeys(std::string& _buffer);

            void getMessageBoxWrapUpList(std::string& _buffer, uint32_t& start, uint32_t& messageBoxCount);

            void leaveRoom(std::string& _buffer, uint32_t& reqSeq, std::string& roomId);

            void unblockRecommendation(std::string& _buffer, uint32_t& reqSeq, std::string& id);

            void findAndAddContactsByPhone(std::string& _buffer, uint32_t& reqSeq, std::set<std::string>& phones);

            void getAuthQrcode(std::string& _buffer, bool& keepLoggedIn, std::string& systemName, bool& returnCallbackUrl);

            void getE2EEGroupSharedKey(std::string& _buffer, uint32_t& version, std::string& chatMid, uint32_t& groupKeyId);

            void getMessageBoxWrapUp(std::string& _buffer, std::string& mid);

            void updateSettingsAttributes(std::string& _buffer, uint32_t& reqSeq, uint32_t& attrBitset, Settings& settings);

            void startVerification(std::string& _buffer, std::string& region, CarrierCode& carrier, std::string& phone, std::string& udidHash, DeviceInfo& deviceInfo, std::string& networkCode, std::string& mid, std::string& locale, SIMInfo& simInfo, std::string& oldUdidHash);

            void reportRooms(std::string& _buffer, uint64_t& syncOpRevision, std::vector<Room>& rooms);

            void updateGroupPreferenceAttribute(std::string& _buffer, uint32_t& reqSeq, std::string& groupMid, std::map<GroupPreferenceAttribute, std::string>& updatedAttrs);

            void getMessageBoxWrapUpV2(std::string& _buffer, std::string& messageBoxId);

            void getCompactRooms(std::string& _buffer, std::vector<std::string>& roomIds);

            void findAndAddContactByMetaTag(std::string& _buffer, uint32_t& reqSeq, std::string& userid, std::string& reference);

            void storeUpdateProfileAttribute(std::string& _buffer, uint32_t& seq, ProfileAttribute& profileAttribute, std::string& value);

            void resendEmailConfirmation(std::string& _buffer, std::string& verifier);

            void confirmEmail(std::string& _buffer, std::string& verifier, std::string& pinCode);

            void getExtendedProfile(std::string& _buffer);

            void isUseridAvailable(std::string& _buffer, std::string& userid);

            void notifyRegistrationComplete(std::string& _buffer, std::string& udidHash, std::string& applicationTypeWithExtensions);

            void updateDeviceInfo(std::string& _buffer, std::string& deviceUid, DeviceInfo& deviceInfo);

            void blockRecommendation(std::string& _buffer, uint32_t& reqSeq, std::string& id);

            void rejectGroupInvitation(std::string& _buffer, uint32_t& reqSeq, std::string& groupId);

            void updateCustomModeSettings(std::string& _buffer, CustomMode& customMode, std::map<std::string, std::string>& paramMap);

            void createRoomV2(std::string& _buffer, uint32_t& reqSeq, std::vector<std::string>& contactIds);

            void noop(std::string& _buffer);

            void acquireEncryptedAccessToken(std::string& _buffer, FeatureType& featureType);

            void getE2EEPublicKeysEx(std::string& _buffer, bool& ignoreE2EEStatus);

            void syncContacts(std::string& _buffer, uint32_t& reqSeq, std::vector<ContactModification>& localContacts);

            void findAndAddContactsByMid(std::string& _buffer, uint32_t& reqSeq, std::set<std::string>& mids);

            void findGroupByTicketV2(std::string& _buffer, std::string& ticketId);

            void removeFriendRequest(std::string& _buffer, FriendRequestDirection& direction, std::string& midOrEMid);

            void verifyPhoneNumber(std::string& _buffer, std::string& sessionId, std::string& pinCode, std::string& udidHash, std::string& migrationPincodeSessionId, std::string& oldUdidHash);

            void setNotificationsEnabled(std::string& _buffer, uint32_t& reqSeq, MIDType& type, std::string& target, bool& enablement);

            void getAllContactIds(std::string& _buffer);

            void getIdentityIdentifier(std::string& _buffer);

            void sendDummyPush(std::string& _buffer);

            void inviteFriendsBySms(std::string& _buffer, std::vector<std::string>& phoneNumberList);

            void getMessageBox(std::string& _buffer, std::string& channelId, std::string& messageBoxId, uint32_t& lastMessagesCount);

            void unsendMessage(std::string& _buffer, uint32_t& reqSeq, std::string& messageId);

            void createChatRoomAnnouncement(std::string& _buffer, uint32_t& reqSeq, std::string& chatRoomMid, uint32_t& type, ChatRoomAnnouncementContents& contents);

            void removeChatRoomAnnouncement(std::string& _buffer, uint32_t& reqSeq, std::string& chatRoomMid, uint64_t& announcementSeq);

            void getChatRoomAnnouncements(std::string& _buffer, std::string& chatRoomMid);

            void getChatRoomAnnouncementsBulk(std::string& _buffer, std::vector<std::string>& chatRoomMids);

            void unregisterBuddy(std::string& _buffer, std::string& requestId);

            void sendBuddyContentMessageToMidsAsync(std::string& _buffer, std::string& requestId, Message& msg, std::string& content, std::vector<std::string>& mids);

            void getAllBuddyMembers(std::string& _buffer);

            void getActiveMemberMidsByBuddyMid(std::string& _buffer, std::string& buddyMid);

            void updateBuddyProfileAttributes(std::string& _buffer, std::string& requestId, std::map<std::string, std::string>& attributes, QueueingPolicy& policy);

            void storePrivateMessages(std::string& _buffer, std::string& requestId, std::vector<PrivateBotMessage>& privateBotMessages, std::string& toMid);

            void updateBuddyProfileImageAsync(std::string& _buffer, std::string& requestId, std::string& image, QueueingPolicy& policy);

            void notifyBuddyBlocked(std::string& _buffer, std::string& buddyMid, std::string& blockerMid);

            void getMemberCountByBuddyMid(std::string& _buffer, std::string& buddyMid);

            void isBuddyOnAirByMid(std::string& _buffer, std::string& buddyMid);

            void commitPrivateMessages(std::string& _buffer, std::string& requestId, std::string& privateMessageStoreRequestId, QueueingPolicy& policy);

            void commitPublicMessagesToMids(std::string& _buffer, std::string& requestId, std::string& publicMessageStoreRequestId, std::vector<std::string>& toMids, QueueingPolicy& policy);

            void addBuddyMember(std::string& _buffer, std::string& requestId, std::string& userMid);

            void linkAndSendBuddyContentMessageToMids(std::string& _buffer, std::string& requestId, Message& msg, std::string& sourceContentId, std::vector<std::string>& mids, bool& usePermanent);

            void storeMessages(std::string& _buffer, std::vector<std::string>& requestIds, std::vector<BuddyMessageRequest>& messageRequests);

            void storeMessage(std::string& _buffer, std::string& requestId, BuddyMessageRequest& messageRequest);

            void registerBuddy(std::string& _buffer, std::string& buddyId, std::string& searchId, std::string& displayName, std::string& statusMeessage, std::string& picture, std::map<std::string, std::string>& settings);

            void getUnregisterBuddyResult(std::string& _buffer, std::string& unregisterBuddyRequestId, std::string& buddyMid);

            void updateBuddySearchId(std::string& _buffer, std::string& requestId, std::string& searchId);

            void uploadBuddyContent(std::string& _buffer, ContentType& contentType, std::string& content);

            void updateBuddyProfileImage(std::string& _buffer, std::string& requestId, std::string& image, QueueingPolicy& policy);

            void sendBuddyMessageToAll(std::string& _buffer, std::string& requestId, Message& msg);

            void commitSendMessagesToAll(std::string& _buffer, std::string& requestId, std::vector<std::string>& commitRequestIdList, uint32_t& priority, QueueingPolicy& policy);

            void downloadMessageContent(std::string& _buffer, std::string& requestId, std::string& messageId);

            void updateBuddyProfileRichMenu(std::string& _buffer, std::string& requestId, QueueingPolicy& policy);

            void setBuddyOnAir(std::string& _buffer, std::string& requestId, bool& onAir, BuddyOnAirLabel& label);

            void unblockBuddyMember(std::string& _buffer, std::string& requestId, std::string& mid);

            void linkAndSendBuddyContentMessageToAll(std::string& _buffer, std::string& requestId, Message& msg, std::string& sourceContentId, bool& usePermanent);

            void removeBuddyMember(std::string& _buffer, std::string& requestId, std::string& userMid);

            void commitSendMessagesToMidAsync(std::string& _buffer, std::string& requestId, std::vector<std::string>& storeMessagesRequestIds, QueueingPolicy& policy);

            void getUpdateBuddyProfileResult(std::string& _buffer, std::string& updateBuddyProfileRequestId);

            void notifyBuddyUnblocked(std::string& _buffer, std::string& buddyMid, std::string& blockerMid);

            void updateBuddyProfileRichMenuAsync(std::string& _buffer, std::string& requestId, QueueingPolicy& policy);

            void getBuddyProfile(std::string& _buffer);

            void getBlockedBuddyMembers(std::string& _buffer);

            void commitPublicMessagesToAll(std::string& _buffer, std::string& requestId, std::string& publicMessageStoreRequestId, QueueingPolicy& policy);

            void linkAndSendBuddyContentMessageToAllAsync(std::string& _buffer, std::string& requestId, Message& msg, std::string& sourceContentId, bool& usePermanent);

            void sendBuddyContentMessageToAllAsync(std::string& _buffer, std::string& requestId, Message& msg, std::string& content);

            void getSetBuddyOnAirResult(std::string& _buffer, std::string& setBuddyOnAirRequestId);

            void commitSendMessagesToMidsAsync(std::string& _buffer, std::string& requestId, std::vector<std::string>& commitRequestIdList, std::vector<std::string>& mids, uint32_t& priority, QueueingPolicy& policy);

            void commitSendMessagesToStoredMidsAsync(std::string& _buffer, std::string& requestId, std::vector<std::string>& commitRequestIdList, std::string& storedMidFilename, uint32_t& priority, QueueingPolicy& policy);

            void updateBuddyAdminProfileAttribute(std::string& _buffer, std::string& requestId, std::map<std::string, std::string>& attributes);

            void setBuddyOnAirAsync(std::string& _buffer, std::string& requestId, bool& onAir, BuddyOnAirLabel& label);

            void commitSendMessagesToMids(std::string& _buffer, std::string& requestId, std::vector<std::string>& commitRequestIdList, std::vector<std::string>& mids, uint32_t& priority, QueueingPolicy& policy);

            void sendBuddyContentMessageToAll(std::string& _buffer, std::string& requestId, Message& msg, std::string& content);

            void updateBuddySettings(std::string& _buffer, std::map<std::string, std::string>& settings);

            void notifyBuddySubscribed(std::string& _buffer, std::string& buddyMid, std::string& subscriberMid);

            void registerBuddyAdmin(std::string& _buffer, std::string& buddyId, std::string& searchId, std::string& displayName, std::string& statusMessage, std::string& picture);

            void getBlockerCountByBuddyMid(std::string& _buffer, std::string& buddyMid);

            void reissueContactTicket(std::string& _buffer, uint64_t& expirationTime, uint32_t& maxUseCount);

            void validateContacts(std::string& _buffer, std::vector<std::string>& userMids);

            void sendBuddyMessageToMidsAsync(std::string& _buffer, std::string& requestId, Message& msg, std::vector<std::string>& mids);

            void unregisterBuddyAsync(std::string& _buffer, std::string& requestId);

            void getProfileImageUrlHash(std::string& _buffer, std::string& requestId);

            void blockBuddyMember(std::string& _buffer, std::string& requestId, std::string& mid);

            void sendIndividualEventToAllAsync(std::string& _buffer, std::string& requestId, std::string& buddyMid, NotificationStatus& notificationStatus);

            void deleteBotProfileImage(std::string& _buffer, std::string& requestId);

            void sendBuddyContentMessageToMids(std::string& _buffer, std::string& requestId, Message& msg, std::string& content, std::vector<std::string>& mids);

            void unregisterBuddyAdmin(std::string& _buffer, std::string& requestId);

            void commitPublicMessagesToStoredMids(std::string& _buffer, std::string& requestId, std::string& publicMessageStoreRequestId, std::string& storedMidFilename, QueueingPolicy& policy);

            void removeBuddyMembers(std::string& _buffer, std::string& requestId, std::vector<std::string>& userMids);

            void storePublicMessages(std::string& _buffer, std::string& requestId, std::vector<Message>& messages);

            void addBuddyMembers(std::string& _buffer, std::string& requestId, std::vector<std::string>& userMids);

            void getMessageCommitResult(std::string& _buffer, std::string& messageCommitRequestId);

            void getBuddyDetailByMid(std::string& _buffer, std::string& buddyMid);

            void notifyBuddySubscriberUnregistered(std::string& _buffer, std::string& buddyMid, std::string& userMid);

            void sendBuddyMessageToAllAsync(std::string& _buffer, std::string& requestId, Message& msg);

            void sendBuddyMessageToMids(std::string& _buffer, std::string& requestId, Message& msg, std::vector<std::string>& mids);

            void commitSendMessagesToAllAsync(std::string& _buffer, std::string& requestId, std::vector<std::string>& commitRequestIdList, uint32_t& priority, QueueingPolicy& policy);

            void notifyBuddySubscriberEmpty(std::string& _buffer, std::string& buddyMid, std::string& userMid);

            void updateBuddyAdminProfileImage(std::string& _buffer, std::string& requestId, std::string& picture);

            void updateBuddyProfileAttributesAsync(std::string& _buffer, std::string& requestId, std::map<std::string, std::string>& attributes, QueueingPolicy& policy);

            void linkAndSendBuddyContentMessageToMidsAsync(std::string& _buffer, std::string& requestId, Message& msg, std::string& sourceContentId, std::vector<std::string>& mids, bool& usePermanent);

            void downloadProfileImagePreview(std::string& _buffer, std::string& requestId);

            void downloadProfileImage(std::string& _buffer, std::string& requestId);

            void getSendBuddyMessageResult(std::string& _buffer, std::string& sendBuddyMessageRequestId);

            void containsBuddyMember(std::string& _buffer, std::string& requestId, std::string& userMid);

            void getActiveMemberCountByBuddyMid(std::string& _buffer, std::string& buddyMid);

            void downloadMessageContentPreview(std::string& _buffer, std::string& requestId, std::string& messageId);

            void notifyBuddyRegistered(std::string& _buffer, std::string& buddyId, std::string& buddyMid, std::string& searchId, std::string& displayName, std::string& statusMessage, std::map<std::string, std::string>& settings);

            void lookupByPhoneNumber(std::string& _buffer, std::string& countryAreaCode, std::string& phoneNumber);

            void lookupNearby(std::string& _buffer, Location& location, SpotCategory& category, std::string& query, std::string& countryAreaCode);

            void checkUserAge(std::string& _buffer, CarrierCode& carrier, std::string& sessionId, std::string& verifier, uint32_t& standardAge);

            void checkUserAgeWithDocomo(std::string& _buffer, std::string& openIdRedirectUrl, uint32_t& standardAge, std::string& verifier);

            void retrieveOpenIdAuthUrlWithDocomo(std::string& _buffer);

            void retrieveRequestToken(std::string& _buffer, CarrierCode& carrier);

            void getBuddyStatusBar(std::string& _buffer, std::string& buddyMid, uint64_t& revision);

            void getRichMenuContents(std::string& _buffer, std::string& buddyMid, uint64_t& revision);

            void getBuddyProfilePopup(std::string& _buffer, std::string& buddyMid);

            void getPopularBuddyBanner(std::string& _buffer, std::string& language, std::string& country, ApplicationType& applicationType, std::string& resourceSpecification);

            void getPopularBuddyLists(std::string& _buffer, std::string& language, std::string& country);

            void findBuddyContactsByQuery(std::string& _buffer, std::string& language, std::string& country, std::string& query, uint32_t& fromIndex, uint32_t& count, BuddySearchRequestSource& requestSource);

            void getBuddyNewsView(std::string& _buffer, std::string& language, std::string& country, uint64_t& offset, uint32_t& limit);

            void getBuddyContacts(std::string& _buffer, std::string& language, std::string& country, std::string& classification, uint32_t& fromIndex, uint32_t& count);

            void getBuddyCollectionEntries(std::string& _buffer, std::string& language, std::string& country, uint32_t& collection, uint32_t& offset, uint32_t& limit);

            void getLatestBuddyNewsTimestamp(std::string& _buffer, std::string& country);

            void getBuddyChatBar(std::string& _buffer, std::string& buddyMid, uint64_t& revision);

            void getCountriesServingOfficialAccountPromotionV2(std::string& _buffer);

            void getBuddyDetail(std::string& _buffer, std::string& buddyMid);

            void getBuddyOnAir(std::string& _buffer, std::string& buddyMid);

            void getNewlyReleasedBuddyIds(std::string& _buffer, std::string& country);

            void getBuddyCategoryView(std::string& _buffer, std::string& language, std::string& country);

            void getCountriesHavingBuddy(std::string& _buffer);

            void getPromotedBuddyContacts(std::string& _buffer, std::string& language, std::string& country);

            void getBuddyTopView(std::string& _buffer, std::string& language, std::string& country);

            void notifyLeaveGroup(std::string& _buffer, std::string& groupMid);

            void notifyLeaveRoom(std::string& _buffer, std::string& roomMid);

            void getBotUseInfo(std::string& _buffer, std::string& botMid);

            void sendChatCheckedByWatermark(std::string& _buffer, uint32_t& seq, std::string& mid, uint64_t& watermark, uint32_t& sessionId);

            void normalizePhoneNumber(std::string& _buffer, std::string& countryCode, std::string& phoneNumber, std::string& countryCodeHint);

            void respondE2EELoginRequest(std::string& _buffer, std::string& verifier, E2EEPublicKey& publicKey, std::string& encryptedKeyChain, std::string& hashKeyChain, ErrorCode& errorCode);

            void confirmE2EELogin(std::string& _buffer, std::string& verifier, std::string& deviceSecret);

            void logoutZ(std::string& _buffer);

            void loginZ(std::string& _buffer, LoginRequest& loginRequest);

            void issueTokenForAccountMigrationSettings(std::string& _buffer, bool& enforce);

            void issueTokenForAccountMigration(std::string& _buffer, std::string& migrationSessionId);

            void verifyQrcodeWithE2EE(std::string& _buffer, std::string& verifier, std::string& pinCode, ErrorCode& errorCode, E2EEPublicKey& publicKey, std::string& encryptedKeyChain, std::string& hashKeyChain);

        } // closing request namespace

        namespace result {

            void ChannelExceptionFunction(std::string& _buffer, ChannelException& _result, const char* _function_name);

            void PointExceptionFunction(std::string& _buffer, PointException& _result, const char* _function_name);

            void ShouldSyncExceptionFunction(std::string& _buffer, ShouldSyncException& _result, const char* _function_name);

            void TalkExceptionFunction(std::string& _buffer, TalkException& _result, const char* _function_name);

            void getMoretabRecommend(std::string& _buffer, MoretabRecommend& _result);

            void requestBanPageForUser(std::string& _buffer, BanPage& _result);

            void requestBanPage(std::string& _buffer, BanPage& _result);

            void reserveCoinPurchase(std::string& _buffer, PaymentReservationResult& _result);

            void getProductCategories(std::string& _buffer, std::vector<ProductCategory>& _result);

            void getProductList(std::string& _buffer, ProductList& _result);

            void getCoinPurchaseHistory(std::string& _buffer, CoinHistoryResult& _result);

            void buyFreeProduct(std::string& _buffer);

            void getProductListWithCarrier(std::string& _buffer, ProductList& _result);

            void getDefaultProducts(std::string& _buffer, ProductList& _result);

            void getProductsForCategory(std::string& _buffer, ProductList& _result);

            void notifyDownloaded(std::string& _buffer, uint64_t& _result);

            void getFreePackagesWithoutEvent(std::string& _buffer, ProductList& _result);

            void getProduct(std::string& _buffer, Product& _result);

            void getEventPackages(std::string& _buffer, ProductList& _result);

            void getActivePurchaseVersions(std::string& _buffer, ProductSimpleList& _result);

            void getCoinProductsByPgCode(std::string& _buffer, std::vector<CoinProductItem>& _result);

            void getNewlyReleasedPackages(std::string& _buffer, ProductList& _result);

            void getDownloads(std::string& _buffer, ProductList& _result);

            void getCoinProducts(std::string& _buffer, std::vector<CoinProductItem>& _result);

            void searchProducts(std::string& _buffer, ProductList& _result);

            void buyMustbuyProduct(std::string& _buffer);

            void getRecommendationsForProduct(std::string& _buffer, ProductList& _result);

            void getUpdates(std::string& _buffer, ShopUpdates& _result);

            void getActivePurchases(std::string& _buffer, ProductList& _result);

            void getProductWithCarrier(std::string& _buffer, Product& _result);

            void buyCoinProduct(std::string& _buffer);

            void getPopularPackages(std::string& _buffer, ProductList& _result);

            void reservePayment(std::string& _buffer, PaymentReservationResult& _result);

            void getPresentsSent(std::string& _buffer, ProductList& _result);

            void checkCanReceivePresent(std::string& _buffer);

            void getFreePackages(std::string& _buffer, ProductList& _result);

            void getPurchaseHistory(std::string& _buffer, ProductList& _result);

            void getTotalBalance(std::string& _buffer, Coin& _result);

            void getCoinUseAndRefundHistory(std::string& _buffer, CoinHistoryResult& _result);

            void getPresentsReceived(std::string& _buffer, ProductList& _result);

            void getPlaceSearchInfo(std::string& _buffer, std::vector<PlaceSearchInfo>& _result);

            void getUserStatus(std::string& _buffer, UserStatus& _result);

            void updateProfileAttributeForChannel(std::string& _buffer);

            void getAllSimpleChannelContacts(std::string& _buffer, std::vector<SimpleChannelContact>& _result);

            void getUserIdentities(std::string& _buffer, std::map<RegistrationType, std::string>& _result);

            void markPaidCallAd(std::string& _buffer, PaidCallDialing& _result);

            void isGroupMember(std::string& _buffer, bool& _result);

            void getPhoneInfoFromPhoneNumber(std::string& _buffer, PhoneInfoForChannel& _result);

            void redeemPaidCallVoucher(std::string& _buffer, PaidCallRedeemResult& _result);

            void getPreferredDisplayName(std::string& _buffer, std::map<std::string, std::string>& _result);

            void getContactsForChannel(std::string& _buffer, std::vector<Contact>& _result);

            void getCallCreditProducts(std::string& _buffer, std::vector<CoinProductItem>& _result);

            void getCompactContacts(std::string& _buffer, std::vector<CompactContact>& _result);

            void notifyNotiCenterEvent(std::string& _buffer);

            void isInContact(std::string& _buffer, bool& _result);

            void lookupGroupMembers(std::string& _buffer, std::vector<SimpleChannelContact>& _result);

            void getRoomInformation(std::string& _buffer, Room& _result);

            void getGroupCall(std::string& _buffer, GroupCall& _result);

            void isAllowSecondaryDeviceLogin(std::string& _buffer, bool& _result);

            void getPrimaryClientForChannel(std::string& _buffer, SimpleChannelClient& _result);

            void createRoomWithBuddy(std::string& _buffer, Room& _result);

            void getDisplayName(std::string& _buffer, std::string& _result);

            void getPaidCallMetadata(std::string& _buffer, PaidCallMetadataResult& _result);

            void getMid(std::string& _buffer, std::string& _result);

            void getUserCountryForBilling(std::string& _buffer, std::string& _result);

            void getFavoriteGroupIdsForChannel(std::string& _buffer, std::vector<std::string>& _result);

            void getPaidCallHistory(std::string& _buffer, PaidCallHistoryResult& _result);

            void sendPinCodeOperation(std::string& _buffer);

            void inviteIntoGroupCall(std::string& _buffer);

            void getFriendMids(std::string& _buffer, std::vector<std::string>& _result);

            void getMetaProfile(std::string& _buffer, MetaProfile& _result);

            void sendMessageForChannel(std::string& _buffer, Message& _result);

            void activeBuddySubscriberCount(std::string& _buffer, uint64_t& _result);

            void getCallCreditPurchaseHistory(std::string& _buffer, CoinHistoryResult& _result);

            void isRoomMember(std::string& _buffer, bool& _result);

            void sendSystemOAMessage(std::string& _buffer, Message& _result);

            void acquirePaidCallRoute(std::string& _buffer, PaidCallResponse& _result);

            void getGroupsForChannel(std::string& _buffer, std::vector<Group>& _result);

            void getUserCreateTime(std::string& _buffer, uint64_t& _result);

            void registerChannelCP(std::string& _buffer, std::string& _result);

            void reserveCallCreditPurchase(std::string& _buffer, PaymentReservationResult& _result);

            void acquirePaidCallCurrencyExchangeRate(std::string& _buffer, std::vector<PaidCallCurrencyExchangeRate>& _result);

            void getRoomMemberMidsForAppPlatform(std::string& _buffer, std::vector<std::string>& _result);

            void getPaidCallBalanceList(std::string& _buffer, std::vector<PaidCallBalance>& _result);

            void getPersonalInfos(std::string& _buffer, std::map<PersonalInfo, std::string>& _result);

            void getPrimaryClientsForChannel(std::string& _buffer, std::vector<SimpleChannelClient>& _result);

            void addBuddyToContact(std::string& _buffer, ContactTransition& _result);

            void getGroupMemberMidsForAppPlatform(std::string& _buffer, std::vector<std::string>& _result);

            void getUserLanguage(std::string& _buffer, std::string& _result);

            void lookupPaidCall(std::string& _buffer, PaidCallResponse& _result);

            void getReverseCompactContacts(std::string& _buffer, std::map<std::string, CompactContact>& _result);

            void getPaidCallAdStatus(std::string& _buffer, PaidCallAdResult& _result);

            void findContactByUseridWithoutAbuseBlockForChannel(std::string& _buffer, Contact& _result);

            void getGroupMemberMids(std::string& _buffer, std::vector<std::string>& _result);

            void sendMessageWithoutRelationship(std::string& _buffer, Message& _result);

            void displayBuddySubscriberCountInBulk(std::string& _buffer, std::map<std::string, uint64_t>& _result);

            void lookupRoomMembers(std::string& _buffer, std::vector<SimpleChannelContact>& _result);

            void getFavoriteMidsForChannel(std::string& _buffer, std::vector<std::string>& _result);

            void getAllContactIdsForChannel(std::string& _buffer, std::vector<std::string>& _result);

            void displayBuddySubscriberCount(std::string& _buffer, uint64_t& _result);

            void getProfileForChannel(std::string& _buffer, Profile& _result);

            void getUserTickets(std::string& _buffer, std::vector<UserTicketResponse>& _result);

            void getOAFriendMids(std::string& _buffer, std::vector<std::string>& _result);

            void searchPaidCallUserRate(std::string& _buffer, std::vector<PaidCallUserRate>& _result);

            void getJoinedGroupIdsForChannel(std::string& _buffer, std::vector<std::string>& _result);

            void acquireGroupCallRoute(std::string& _buffer, GroupCallRoute& _result);

            void getUserMidsWhoAddedMe(std::string& _buffer, std::vector<std::string>& _result);

            void getIdentityCredential(std::string& _buffer, IdentityCredential& _result);

            void addOperationForChannel(std::string& _buffer);

            void getSimpleChannelContacts(std::string& _buffer, std::vector<SimpleChannelContact>& _result);

            void getUserLastSentMessageTimeStamp(std::string& _buffer, uint64_t& _result);

            void registerVirtualAccount(std::string& _buffer, std::string& _result);

            void unregisterVirtualAccount(std::string& _buffer);

            void requestVirtualAccountPasswordChange(std::string& _buffer);

            void notifyEmailConfirmationResult(std::string& _buffer);

            void requestVirtualAccountPasswordSet(std::string& _buffer);

            void getRSAKey(std::string& _buffer, RSAKey& _result);

            void queryBeaconActions(std::string& _buffer, BeaconQueryResponse& _result);

            void notifyBeaconDetected(std::string& _buffer);

            void getDomains(std::string& _buffer, ChannelDomains& _result);

            void approveChannelAndIssueRequestToken(std::string& _buffer, std::string& _result);

            void issueOTP(std::string& _buffer, OTPResult& _result);

            void getChannelSettings(std::string& _buffer, ChannelSettings& _result);

            void getChannelNotificationSettings(std::string& _buffer, std::vector<ChannelNotificationSetting>& _result);

            void updateChannelNotificationSetting(std::string& _buffer);

            void updateChannelSettings(std::string& _buffer, bool& _result);

            void getCommonDomains(std::string& _buffer, ChannelDomains& _result);

            void issueRequestTokenWithAuthScheme(std::string& _buffer, RequestTokenResponse& _result);

            void getChannelNotificationSetting(std::string& _buffer, ChannelNotificationSetting& _result);

            void issueChannelToken(std::string& _buffer, ChannelToken& _result);

            void getChannels(std::string& _buffer, ChannelInfos& _result);

            void fetchNotificationItems(std::string& _buffer, NotificationFetchResult& _result);

            void getChannelInfo(std::string& _buffer, ChannelInfo& _result);

            void getNotificationBadgeCount(std::string& _buffer, uint32_t& _result);

            void issueRequestToken(std::string& _buffer, std::string& _result);

            void revokeChannel(std::string& _buffer);

            void getApprovedChannels(std::string& _buffer, ApprovedChannelInfos& _result);

            void getFriendChannelMatrices(std::string& _buffer, FriendChannelMatricesResponse& _result);

            void issueRequestTokenForAutoLogin(std::string& _buffer, std::string& _result);

            void getUpdatedChannelIds(std::string& _buffer, std::vector<std::string>& _result);

            void reserveCoinUse(std::string& _buffer, std::string& _result);

            void syncChannelData(std::string& _buffer, ChannelSyncDatas& _result);

            void approveChannelAndIssueChannelToken(std::string& _buffer, ChannelToken& _result);

            void getSnsFriends(std::string& _buffer, SnsFriends& _result);

            void getSnsMyProfile(std::string& _buffer, SnsProfile& _result);

            void postSnsInvitationMessage(std::string& _buffer);

            void reportDeviceState(std::string& _buffer);

            void notifySleepV2(std::string& _buffer);

            void updateNotificationToken(std::string& _buffer);

            void updateGroup(std::string& _buffer);

            void verifyAccountMigrationPincode(std::string& _buffer);

            void registerWithExistingSnsIdAndIdentityCredential(std::string& _buffer, std::string& _result);

            void registerDeviceWithoutPhoneNumber(std::string& _buffer, std::string& _result);

            void changeVerificationMethod(std::string& _buffer, VerificationSessionData& _result);

            void setBuddyLocation(std::string& _buffer);

            void getFriendRequests(std::string& _buffer, std::vector<FriendRequest>& _result);

            void kickoutFromGroup(std::string& _buffer);

            void verifyIdentityCredentialWithResult(std::string& _buffer, UserAuthStatus& _result);

            void sendEchoPush(std::string& _buffer);

            void createSession(std::string& _buffer, std::string& _result);

            void reissueDeviceCredential(std::string& _buffer, std::string& _result);

            void getRecommendationIds(std::string& _buffer, std::vector<std::string>& _result);

            void inviteViaEmail(std::string& _buffer);

            void getRoomsV2(std::string& _buffer, std::vector<Room>& _result);

            void getReadMessageOps(std::string& _buffer, std::vector<Operation>& _result);

            void getSettingsAttributes(std::string& _buffer, Settings& _result);

            void requestIdentityUnbind(std::string& _buffer);

            void getMessagesBySequenceNumber(std::string& _buffer, std::vector<Message>& _result);

            void inviteIntoRoom(std::string& _buffer);

            void sendChatChecked(std::string& _buffer);

            void removeSnsId(std::string& _buffer, std::string& _result);

            void reportSpammer(std::string& _buffer);

            void findAndAddContactsByEmail(std::string& _buffer, std::map<std::string, Contact>& _result);

            void getCompactGroups(std::string& _buffer, std::vector<Group>& _result);

            void sendMessage(std::string& _buffer, Message& _result);

            void getRooms(std::string& _buffer, std::vector<Room>& _result);

            void updateC2DMRegistrationId(std::string& _buffer);

            void sendPostback(std::string& _buffer);

            void getReadMessageOpsInBulk(std::string& _buffer, std::vector<Operation>& _result);

            void sendMessageIgnored(std::string& _buffer);

            void getMessageBoxWrapUpListV2(std::string& _buffer, TMessageBoxWrapUpResponse& _result);

            void getOldReadMessageOpsWithRange(std::string& _buffer, std::vector<Operation>& _result);

            void getRSAKeyInfo(std::string& _buffer, RSAKey& _result);

            void updateProfileAttribute(std::string& _buffer);

            void createAccountMigrationPincodeSession(std::string& _buffer, std::string& _result);

            void notifiedRedirect(std::string& _buffer);

            void notifyIndividualEvent(std::string& _buffer);

            void updateApnsDeviceToken(std::string& _buffer);

            void getMessageBoxCompactWrapUpListV2(std::string& _buffer, TMessageBoxWrapUpResponse& _result);

            void requestEmailConfirmation(std::string& _buffer, EmailConfirmationSession& _result);

            void registerWithSnsIdAndIdentityCredential(std::string& _buffer, std::string& _result);

            void getMessageBoxCompactWrapUp(std::string& _buffer, TMessageBoxWrapUp& _result);

            void findContactByUserTicket(std::string& _buffer, Contact& _result);

            void updateAccountMigrationPincode(std::string& _buffer);

            void registerBuddyUser(std::string& _buffer, std::string& _result);

            void updateSettingsV2(std::string& _buffer, uint32_t& _result);

            void getUserTicket(std::string& _buffer, Ticket& _result);

            void fetchOps(std::string& _buffer, std::vector<Operation>& _result);

            void commitSendMessagesToMid(std::string& _buffer, CommitSendMessagesToMidResponse& _result);

            void getMessageBoxV2(std::string& _buffer, TMessageBox& _result);

            void requestResendMessage(std::string& _buffer);

            void getGroupWithoutMembers(std::string& _buffer, Group& _result);

            void removeAllMessages(std::string& _buffer);

            void verifyAccountMigration(std::string& _buffer);

            void reissueGroupTicket(std::string& _buffer, std::string& _result);

            void logoutSession(std::string& _buffer);

            void getBuddyLocation(std::string& _buffer, Geolocation& _result);

            void getWapInvitation(std::string& _buffer, WapInvitation& _result);

            void registerDevice(std::string& _buffer, std::string& _result);

            void clearMessageBox(std::string& _buffer);

            void loginWithIdentityCredentialForCertificate(std::string& _buffer, LoginResult& _result);

            void getSuggestSettings(std::string& _buffer, SuggestDictionarySettings& _result);

            void updateAndGetNearby(std::string& _buffer, std::vector<NearbyEntry>& _result);

            void syncContactBySnsIds(std::string& _buffer, std::vector<SnsFriendContactRegistration>& _result);

            void getContacts(std::string& _buffer, std::vector<Contact>& _result);

            void getMessageBoxCompactWrapUpList(std::string& _buffer, TMessageBoxWrapUpResponse& _result);

            void getProximityMatchCandidates(std::string& _buffer, std::set<Contact>& _result);

            void updateExtendedProfileAttribute(std::string& _buffer);

            void resendPinCode(std::string& _buffer);

            void reportSettings(std::string& _buffer);

            void registerBuddyUserid(std::string& _buffer);

            void findGroupByTicket(std::string& _buffer, Group& _result);

            void registerDeviceWithIdentityCredential(std::string& _buffer, std::string& _result);

            void invalidateUserTicket(std::string& _buffer);

            void sendEvent(std::string& _buffer, Message& _result);

            void sendMessageToMyHome(std::string& _buffer, Message& _result);

            void sendContentPreviewUpdated(std::string& _buffer, std::map<std::string, std::string>& _result);

            void loginWithVerifier(std::string& _buffer, std::string& _result);

            void removeBuddySubscriptionAndNotifyBuddyUnregistered(std::string& _buffer);

            void unblockContact(std::string& _buffer);

            void removeBuddyLocation(std::string& _buffer);

            void getRingbackTone(std::string& _buffer, RingbackTone& _result);

            void getConfigurations(std::string& _buffer, Configurations& _result);

            void getProximityMatchCandidateList(std::string& _buffer, ProximityMatchCandidateResult& _result);

            void requestAccountPasswordReset(std::string& _buffer);

            void getNextMessages(std::string& _buffer, std::vector<Message>& _result);

            void reportProfile(std::string& _buffer);

            void getCompactRoom(std::string& _buffer, Room& _result);

            void getLastOpRevision(std::string& _buffer, uint64_t& _result);

            void getPreviousMessagesV2(std::string& _buffer, std::vector<Message>& _result);

            void fetchAnnouncements(std::string& _buffer, std::vector<Announcement>& _result);

            void acquireCallRoute(std::string& _buffer, std::vector<std::string>& _result);

            void updateSettingsAttribute(std::string& _buffer);

            void createGroupV2(std::string& _buffer, Group& _result);

            void isIdentityIdentifierAvailable(std::string& _buffer, bool& _result);

            void blockContact(std::string& _buffer);

            void commitUpdateProfile(std::string& _buffer, std::map<std::string, std::string>& _result);

            void registerWithSnsId(std::string& _buffer, RegisterWithSnsIdResult& _result);

            void updatePublicKeychain(std::string& _buffer, PublicKeychain& _result);

            void loginWithVerifierForCerificate(std::string& _buffer, LoginResult& _result);

            void tryFriendRequest(std::string& _buffer);

            void getBlockedRecommendationIds(std::string& _buffer, std::vector<std::string>& _result);

            void getGroupIdsInvited(std::string& _buffer, std::vector<std::string>& _result);

            void getSuggestIncrements(std::string& _buffer, SuggestDictionaryIncrements& _result);

            void resendPinCodeBySMS(std::string& _buffer);

            void registerWithPhoneNumber(std::string& _buffer, RegisterWithPhoneNumberResult& _result);

            void getActiveBuddySubscriberIds(std::string& _buffer, std::vector<std::string>& _result);

            void createRoom(std::string& _buffer, Room& _result);

            void verifyPhoneNumberForLogin(std::string& _buffer, std::string& _result);

            void addSnsId(std::string& _buffer, std::string& _result);

            void finishUpdateVerification(std::string& _buffer);

            void validateContactsOnBot(std::string& _buffer, std::map<std::string, std::string>& _result);

            void getRoom(std::string& _buffer, Room& _result);

            void closeProximityMatch(std::string& _buffer);

            void getCompactGroup(std::string& _buffer, Group& _result);

            void getBlockedContactIdsByRange(std::string& _buffer, std::vector<std::string>& _result);

            void getRecentMessagesV2(std::string& _buffer, std::vector<Message>& _result);

            void reissueUserTicket(std::string& _buffer, std::string& _result);

            void getMessageReadRange(std::string& _buffer, std::vector<TMessageReadRange>& _result);

            void clearRingbackTone(std::string& _buffer);

            void setIdentityCredential(std::string& _buffer);

            void getMessageBoxCompactWrapUpV2(std::string& _buffer, TMessageBoxWrapUp& _result);

            void getServerTime(std::string& _buffer, uint64_t& _result);

            void trySendMessage(std::string& _buffer, Message& _result);

            void getNextMessagesV2(std::string& _buffer, std::vector<Message>& _result);

            void notifySleep(std::string& _buffer);

            void getBuddyBlockerIds(std::string& _buffer, std::vector<std::string>& _result);

            void removeE2EEPublicKey(std::string& _buffer);

            void reissueTrackingTicket(std::string& _buffer, std::string& _result);

            void cancelGroupInvitation(std::string& _buffer);

            void removeMessage(std::string& _buffer, bool& _result);

            void getAllReadMessageOps(std::string& _buffer, std::vector<Operation>& _result);

            void unregisterUserAndDevice(std::string& _buffer, std::string& _result);

            void acceptGroupInvitation(std::string& _buffer);

            void getCompactContactsModifiedSince(std::string& _buffer, std::vector<CompactContact>& _result);

            void releaseSession(std::string& _buffer);

            void findContactsByPhone(std::string& _buffer, std::map<std::string, Contact>& _result);

            void getHiddenContactMids(std::string& _buffer, std::vector<std::string>& _result);

            void getEncryptedIdentity(std::string& _buffer, std::string& _result);

            void updateProfile(std::string& _buffer);

            void reportSpam(std::string& _buffer);

            void getSuggestRevisions(std::string& _buffer, SuggestDictionaryRevisions& _result);

            void getPreviousMessagesV2WithReadCount(std::string& _buffer, std::vector<Message>& _result);

            void fetchOperations(std::string& _buffer, std::vector<Operation>& _result);

            void registerWapDevice(std::string& _buffer, std::string& _result);

            void getRecentFriendRequests(std::string& _buffer, FriendRequestsInfo& _result);

            void notifyBuddyOnAir(std::string& _buffer, std::map<std::string, std::string>& _result);

            void getLastAnnouncementIndex(std::string& _buffer, uint32_t& _result);

            void sendMessageAwaitCommit(std::string& _buffer, CommitMessageResult& _result);

            void negotiateE2EEPublicKey(std::string& _buffer, E2EENegotiationResult& _result);

            void registerE2EEGroupKey(std::string& _buffer, E2EEGroupSharedKey& _result);

            void findSnsIdUserStatus(std::string& _buffer, SnsIdUserStatus& _result);

            void notifyUpdated(std::string& _buffer);

            void reportGroups(std::string& _buffer);

            void getNotificationPolicy(std::string& _buffer, std::vector<NotificationType>& _result);

            void findAndAddContactsByUserid(std::string& _buffer, std::map<std::string, Contact>& _result);

            void getLastE2EEGroupSharedKey(std::string& _buffer, E2EEGroupSharedKey& _result);

            void notifyUpdatePublicKeychain(std::string& _buffer);

            void report(std::string& _buffer);

            void acceptGroupInvitationByTicket(std::string& _buffer);

            void getContactRegistration(std::string& _buffer, ContactRegistration& _result);

            void updateContactSetting(std::string& _buffer);

            void getContactWithFriendRequestStatus(std::string& _buffer, Contact& _result);

            void getMessageBoxListByStatus(std::string& _buffer, std::vector<TMessageBox>& _result);

            void openProximityMatch(std::string& _buffer, std::string& _result);

            void logout(std::string& _buffer);

            void getE2EEPublicKey(std::string& _buffer, E2EEPublicKey& _result);

            void registerUserid(std::string& _buffer, bool& _result);

            void reportContacts(std::string& _buffer, std::vector<ContactReportResult>& _result);

            void getPublicKeychain(std::string& _buffer, PublicKeychain& _result);

            void sendContentReceipt(std::string& _buffer);

            void respondResendMessage(std::string& _buffer);

            void getAllRoomIds(std::string& _buffer, std::set<std::string>& _result);

            void requestE2EEKeyExchange(std::string& _buffer);

            void disableNearby(std::string& _buffer);

            void createQrcodeBase64Image(std::string& _buffer, std::string& _result);

            void getMessageBoxList(std::string& _buffer, std::vector<TMessageBox>& _result);

            void respondE2EEKeyExchange(std::string& _buffer);

            void verifyQrcode(std::string& _buffer, std::string& _result);

            void updateNotificationTokenWithBytes(std::string& _buffer);

            void getPreviousMessages(std::string& _buffer, std::vector<Message>& _result);

            void getSettings(std::string& _buffer, Settings& _result);

            void getLastE2EEPublicKeys(std::string& _buffer, std::map<std::string, E2EEPublicKey>& _result);

            void registerE2EEPublicKey(std::string& _buffer, E2EEPublicKey& _result);

            void acquireCallTicket(std::string& _buffer, std::string& _result);

            void inviteIntoGroup(std::string& _buffer);

            void makeUserAddMyselfAsContact(std::string& _buffer, ContactTransition& _result);

            void removeMessageFromMyHome(std::string& _buffer, bool& _result);

            void commitSendMessages(std::string& _buffer, std::map<std::string, std::string>& _result);

            void registerWithPhoneNumberAndPassword(std::string& _buffer, RegisterWithPhoneNumberResult& _result);

            void leaveGroup(std::string& _buffer);

            void getAnalyticsInfo(std::string& _buffer, AnalyticsInfo& _result);

            void reportClientStatistics(std::string& _buffer);

            void acceptProximityMatches(std::string& _buffer);

            void getGroup(std::string& _buffer, Group& _result);

            void clearIdentityCredential(std::string& _buffer);

            void getUpdatedMessageBoxIds(std::string& _buffer, std::vector<std::string>& _result);

            void getGroups(std::string& _buffer, std::vector<Group>& _result);

            void sendMessageReceipt(std::string& _buffer);

            void findContactByMetaTag(std::string& _buffer, Contact& _result);

            void destroyMessage(std::string& _buffer);

            void generateUserTicket(std::string& _buffer, Ticket& _result);

            void registerDeviceWithoutPhoneNumberWithIdentityCredential(std::string& _buffer, std::string& _result);

            void getFavoriteMids(std::string& _buffer, std::vector<std::string>& _result);

            void getAcceptedProximityMatches(std::string& _buffer, std::set<std::string>& _result);

            void notifyInstalled(std::string& _buffer);

            void getCountryWithRequestIp(std::string& _buffer, std::string& _result);

            void getGroupsV2(std::string& _buffer, std::vector<Group>& _result);

            void loginWithIdentityCredential(std::string& _buffer, std::string& _result);

            void startUpdateVerification(std::string& _buffer, VerificationSessionData& _result);

            void getSessions(std::string& _buffer, std::vector<LoginSession>& _result);

            void updateSettings(std::string& _buffer);

            void getContact(std::string& _buffer, Contact& _result);

            void getBlockedContactIds(std::string& _buffer, std::vector<std::string>& _result);

            void loginWithVerifierForCertificate(std::string& _buffer, LoginResult& _result);

            void getProfile(std::string& _buffer, Profile& _result);

            void findContactsByEmail(std::string& _buffer, std::map<std::string, Contact>& _result);

            void getSystemConfiguration(std::string& _buffer, SystemConfiguration& _result);

            void getRecentMessages(std::string& _buffer, std::vector<Message>& _result);

            void verifyPhone(std::string& _buffer, VerificationResult& _result);

            void createGroup(std::string& _buffer, Group& _result);

            void updateBuddySetting(std::string& _buffer);

            void updateRegion(std::string& _buffer);

            void verifyIdentityCredential(std::string& _buffer);

            void sendChatRemoved(std::string& _buffer);

            void getGroupIdsJoined(std::string& _buffer, std::vector<std::string>& _result);

            void findContactByUserid(std::string& _buffer, Contact& _result);

            void getE2EEPublicKeys(std::string& _buffer, std::vector<E2EEPublicKey>& _result);

            void getMessageBoxWrapUpList(std::string& _buffer, TMessageBoxWrapUpResponse& _result);

            void leaveRoom(std::string& _buffer);

            void unblockRecommendation(std::string& _buffer);

            void findAndAddContactsByPhone(std::string& _buffer, std::map<std::string, Contact>& _result);

            void getAuthQrcode(std::string& _buffer, AuthQrcode& _result);

            void getE2EEGroupSharedKey(std::string& _buffer, E2EEGroupSharedKey& _result);

            void getMessageBoxWrapUp(std::string& _buffer, TMessageBoxWrapUp& _result);

            void updateSettingsAttributes(std::string& _buffer, uint32_t& _result);

            void startVerification(std::string& _buffer, VerificationSessionData& _result);

            void reportRooms(std::string& _buffer);

            void updateGroupPreferenceAttribute(std::string& _buffer);

            void getMessageBoxWrapUpV2(std::string& _buffer, TMessageBoxWrapUp& _result);

            void getCompactRooms(std::string& _buffer, std::vector<Room>& _result);

            void findAndAddContactByMetaTag(std::string& _buffer, Contact& _result);

            void storeUpdateProfileAttribute(std::string& _buffer);

            void resendEmailConfirmation(std::string& _buffer, EmailConfirmationSession& _result);

            void confirmEmail(std::string& _buffer, EmailConfirmationResult& _result);

            void getExtendedProfile(std::string& _buffer, ExtendedProfile& _result);

            void isUseridAvailable(std::string& _buffer, bool& _result);

            void notifyRegistrationComplete(std::string& _buffer);

            void updateDeviceInfo(std::string& _buffer);

            void blockRecommendation(std::string& _buffer);

            void rejectGroupInvitation(std::string& _buffer);

            void updateCustomModeSettings(std::string& _buffer);

            void createRoomV2(std::string& _buffer, Room& _result);

            void noop(std::string& _buffer);

            void acquireEncryptedAccessToken(std::string& _buffer, std::string& _result);

            void getE2EEPublicKeysEx(std::string& _buffer, std::vector<E2EEPublicKey>& _result);

            void syncContacts(std::string& _buffer, std::map<std::string, ContactRegistration>& _result);

            void findAndAddContactsByMid(std::string& _buffer, std::map<std::string, Contact>& _result);

            void findGroupByTicketV2(std::string& _buffer, Group& _result);

            void removeFriendRequest(std::string& _buffer);

            void verifyPhoneNumber(std::string& _buffer, PhoneVerificationResult& _result);

            void setNotificationsEnabled(std::string& _buffer);

            void getAllContactIds(std::string& _buffer, std::vector<std::string>& _result);

            void getIdentityIdentifier(std::string& _buffer, std::string& _result);

            void sendDummyPush(std::string& _buffer);

            void inviteFriendsBySms(std::string& _buffer);

            void getMessageBox(std::string& _buffer, TMessageBox& _result);

            void unsendMessage(std::string& _buffer);

            void createChatRoomAnnouncement(std::string& _buffer, ChatRoomAnnouncement& _result);

            void removeChatRoomAnnouncement(std::string& _buffer);

            void getChatRoomAnnouncements(std::string& _buffer, std::vector<ChatRoomAnnouncement>& _result);

            void getChatRoomAnnouncementsBulk(std::string& _buffer, std::vector<ChatRoomAnnouncement>& _result);

            void unregisterBuddy(std::string& _buffer);

            void sendBuddyContentMessageToMidsAsync(std::string& _buffer, std::string& _result);

            void getAllBuddyMembers(std::string& _buffer, std::vector<std::string>& _result);

            void getActiveMemberMidsByBuddyMid(std::string& _buffer, std::vector<std::string>& _result);

            void updateBuddyProfileAttributes(std::string& _buffer, UpdateBuddyProfileResult& _result);

            void storePrivateMessages(std::string& _buffer, MessageStoreResult& _result);

            void updateBuddyProfileImageAsync(std::string& _buffer, std::string& _result);

            void notifyBuddyBlocked(std::string& _buffer);

            void getMemberCountByBuddyMid(std::string& _buffer, uint64_t& _result);

            void isBuddyOnAirByMid(std::string& _buffer, bool& _result);

            void commitPrivateMessages(std::string& _buffer);

            void commitPublicMessagesToMids(std::string& _buffer);

            void addBuddyMember(std::string& _buffer);

            void linkAndSendBuddyContentMessageToMids(std::string& _buffer, SendBuddyMessageResult& _result);

            void storeMessages(std::string& _buffer, std::vector<SendBuddyMessageResult>& _result);

            void storeMessage(std::string& _buffer, SendBuddyMessageResult& _result);

            void registerBuddy(std::string& _buffer, std::string& _result);

            void getUnregisterBuddyResult(std::string& _buffer, UnregisterBuddyResult& _result);

            void updateBuddySearchId(std::string& _buffer);

            void uploadBuddyContent(std::string& _buffer, std::string& _result);

            void updateBuddyProfileImage(std::string& _buffer, UpdateBuddyProfileResult& _result);

            void sendBuddyMessageToAll(std::string& _buffer, SendBuddyMessageResult& _result);

            void commitSendMessagesToAll(std::string& _buffer, SendBuddyMessageResult& _result);

            void downloadMessageContent(std::string& _buffer, std::string& _result);

            void updateBuddyProfileRichMenu(std::string& _buffer, UpdateBuddyProfileResult& _result);

            void setBuddyOnAir(std::string& _buffer, SetBuddyOnAirResult& _result);

            void unblockBuddyMember(std::string& _buffer);

            void linkAndSendBuddyContentMessageToAll(std::string& _buffer, SendBuddyMessageResult& _result);

            void removeBuddyMember(std::string& _buffer);

            void commitSendMessagesToMidAsync(std::string& _buffer, std::string& _result);

            void getUpdateBuddyProfileResult(std::string& _buffer, UpdateBuddyProfileResult& _result);

            void notifyBuddyUnblocked(std::string& _buffer);

            void updateBuddyProfileRichMenuAsync(std::string& _buffer, std::string& _result);

            void getBuddyProfile(std::string& _buffer, BuddyProfile& _result);

            void getBlockedBuddyMembers(std::string& _buffer, std::vector<std::string>& _result);

            void commitPublicMessagesToAll(std::string& _buffer);

            void linkAndSendBuddyContentMessageToAllAsync(std::string& _buffer, std::string& _result);

            void sendBuddyContentMessageToAllAsync(std::string& _buffer, std::string& _result);

            void getSetBuddyOnAirResult(std::string& _buffer, SetBuddyOnAirResult& _result);

            void commitSendMessagesToMidsAsync(std::string& _buffer, std::string& _result);

            void commitSendMessagesToStoredMidsAsync(std::string& _buffer, std::string& _result);

            void updateBuddyAdminProfileAttribute(std::string& _buffer);

            void setBuddyOnAirAsync(std::string& _buffer, std::string& _result);

            void commitSendMessagesToMids(std::string& _buffer, SendBuddyMessageResult& _result);

            void sendBuddyContentMessageToAll(std::string& _buffer, SendBuddyMessageResult& _result);

            void updateBuddySettings(std::string& _buffer);

            void notifyBuddySubscribed(std::string& _buffer);

            void registerBuddyAdmin(std::string& _buffer, std::string& _result);

            void getBlockerCountByBuddyMid(std::string& _buffer, uint64_t& _result);

            void reissueContactTicket(std::string& _buffer, std::string& _result);

            void validateContacts(std::string& _buffer, ValidateContactsResult& _result);

            void sendBuddyMessageToMidsAsync(std::string& _buffer, std::string& _result);

            void unregisterBuddyAsync(std::string& _buffer);

            void getProfileImageUrlHash(std::string& _buffer, std::string& _result);

            void blockBuddyMember(std::string& _buffer);

            void sendIndividualEventToAllAsync(std::string& _buffer);

            void deleteBotProfileImage(std::string& _buffer);

            void sendBuddyContentMessageToMids(std::string& _buffer, SendBuddyMessageResult& _result);

            void unregisterBuddyAdmin(std::string& _buffer);

            void commitPublicMessagesToStoredMids(std::string& _buffer);

            void removeBuddyMembers(std::string& _buffer);

            void storePublicMessages(std::string& _buffer, MessageStoreResult& _result);

            void addBuddyMembers(std::string& _buffer);

            void getMessageCommitResult(std::string& _buffer, MessageCommitResult& _result);

            void getBuddyDetailByMid(std::string& _buffer, BuddyDetail& _result);

            void notifyBuddySubscriberUnregistered(std::string& _buffer);

            void sendBuddyMessageToAllAsync(std::string& _buffer, std::string& _result);

            void sendBuddyMessageToMids(std::string& _buffer, SendBuddyMessageResult& _result);

            void commitSendMessagesToAllAsync(std::string& _buffer, std::string& _result);

            void notifyBuddySubscriberEmpty(std::string& _buffer);

            void updateBuddyAdminProfileImage(std::string& _buffer);

            void updateBuddyProfileAttributesAsync(std::string& _buffer, std::string& _result);

            void linkAndSendBuddyContentMessageToMidsAsync(std::string& _buffer, std::string& _result);

            void downloadProfileImagePreview(std::string& _buffer, std::string& _result);

            void downloadProfileImage(std::string& _buffer, std::string& _result);

            void getSendBuddyMessageResult(std::string& _buffer, SendBuddyMessageResult& _result);

            void containsBuddyMember(std::string& _buffer, bool& _result);

            void getActiveMemberCountByBuddyMid(std::string& _buffer, uint64_t& _result);

            void downloadMessageContentPreview(std::string& _buffer, std::string& _result);

            void notifyBuddyRegistered(std::string& _buffer);

            void lookupByPhoneNumber(std::string& _buffer, SpotPhoneNumberResponse& _result);

            void lookupNearby(std::string& _buffer, SpotNearbyResponse& _result);

            void checkUserAge(std::string& _buffer, UserAgeType& _result);

            void checkUserAgeWithDocomo(std::string& _buffer, AgeCheckDocomoResult& _result);

            void retrieveOpenIdAuthUrlWithDocomo(std::string& _buffer, std::string& _result);

            void retrieveRequestToken(std::string& _buffer, AgeCheckRequestResult& _result);

            void getBuddyStatusBar(std::string& _buffer, BuddyStatusBar& _result);

            void getRichMenuContents(std::string& _buffer, BuddyRichMenuContents& _result);

            void getBuddyProfilePopup(std::string& _buffer, BuddyProfilePopup& _result);

            void getPopularBuddyBanner(std::string& _buffer, BuddyBanner& _result);

            void getPopularBuddyLists(std::string& _buffer, std::vector<BuddyList>& _result);

            void findBuddyContactsByQuery(std::string& _buffer, std::vector<BuddySearchResult>& _result);

            void getBuddyNewsView(std::string& _buffer, BuddyNewsView& _result);

            void getBuddyContacts(std::string& _buffer, std::vector<Contact>& _result);

            void getBuddyCollectionEntries(std::string& _buffer, std::vector<BuddyCollectionEntry>& _result);

            void getLatestBuddyNewsTimestamp(std::string& _buffer, uint64_t& _result);

            void getBuddyChatBar(std::string& _buffer, BuddyChatBar& _result);

            void getCountriesServingOfficialAccountPromotionV2(std::string& _buffer, std::set<std::string>& _result);

            void getBuddyDetail(std::string& _buffer, BuddyDetail& _result);

            void getBuddyOnAir(std::string& _buffer, BuddyOnAir& _result);

            void getNewlyReleasedBuddyIds(std::string& _buffer, std::map<std::string, uint64_t>& _result);

            void getBuddyCategoryView(std::string& _buffer, BuddyCategoryView& _result);

            void getCountriesHavingBuddy(std::string& _buffer, std::vector<std::string>& _result);

            void getPromotedBuddyContacts(std::string& _buffer, std::vector<Contact>& _result);

            void getBuddyTopView(std::string& _buffer, BuddyTopView& _result);

            void notifyLeaveGroup(std::string& _buffer);

            void notifyLeaveRoom(std::string& _buffer);

            void getBotUseInfo(std::string& _buffer, BotUseInfo& _result);

            void sendChatCheckedByWatermark(std::string& _buffer);

            void normalizePhoneNumber(std::string& _buffer, std::string& _result);

            void respondE2EELoginRequest(std::string& _buffer);

            void confirmE2EELogin(std::string& _buffer, std::string& _result);

            void logoutZ(std::string& _buffer);

            void loginZ(std::string& _buffer, LoginResult& _result);

            void issueTokenForAccountMigrationSettings(std::string& _buffer, SecurityCenterResult& _result);

            void issueTokenForAccountMigration(std::string& _buffer, SecurityCenterResult& _result);

            void verifyQrcodeWithE2EE(std::string& _buffer, std::string& _result);

        } // closing result namespace

    } // closing write namespace

} // closing main namespace

#endif // !THRIFT_LINE_H