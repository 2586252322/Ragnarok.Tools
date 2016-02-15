#ifndef __MY_CHRVIEW__
#define __MY_CHRVIEW__

#include <libintl.h>
#include <locale.h>

#ifdef WIN32
#include <windows.h>
#endif

#include <GL/gl.h>
#include <GL/glu.h>

#include "../common/global.h"
#include "../common/pak.h"
#include "../common/Sprite.h"
#include "../common/vec.h"
#include "../common/codeconv.h"

#define GL_WIN_WIDTH 300
#define GL_WIN_HEIGHT 300

#define MAX_PC_PAT 9

typedef struct {
  char *filename;
  char *dispname;
} NAME_FvsD;

typedef struct {
  int num;
  NAME_FvsD *name;
} NFD;

#ifndef WIN32
typedef long LONG;

typedef struct {
  LONG x, y;
} POINT;
#endif

typedef struct {
  POINT *offs;
} POINTs;

typedef struct {
  char name[256];
  POINTs *ofs;
} HEADOffs;

class CChrView
{
private:
  CPAK *pak1;

  void InitNFDMob(char *fnp, NFD *nfd);
  void InitNFDPCBody(char *fnp, NFD *nfd, char *suffix);
  void InitNFDPCAcc(char *fnp, NFD *nfd);
  void InitNFDNPC(char *fnp, NFD *nfd);
  void InitNFDADD(char *dn, char *fn, NFD *nfd);
  void TrimDirSuffix(char *to, char *from, int leftlen);

  char *GetNFDFnameFromDname(NFD *nfd, char *dispname);
  void ChangeToSpr(char *fname, char *sprname);
  void GetItemNoToWeaponType(char *fname, int no);

public:
  CChrView(CPAK *pak);
  virtual ~CChrView();

  bool inMDragging;
  bool inRDragging;
  POINT first_mp, old_mp, new_mp;
  CAM_STATE camera;

  NFD NFDMob;
  NFD NFDPCBodyM;
  NFD NFDPCBodyF;
  NFD NFDPCAccM;
  NFD NFDPCAccF;
  NFD NFDPCWeapon;
  NFD NFDPCShield;
  NFD NFDNPC;

  bool sprready;
  CSprite *sprite_Body;
  CSprite *sprite_Head;
  CSprite *sprite_Acc1;
  CSprite *sprite_Acc2;
  CSprite *sprite_Acc3;
  CSprite *sprite_Weapon;
  CSprite *sprite_WpAftimg;
  CSprite *sprite_Shield;
  int curAct, curPat;
  int numAct, numPat;
  int curdirection;
  int curHead;
  int curAcc1, curAcc2, curAcc3;
  DWORD colBG;

  void DestroySpriteAll(void);
  void DestroySprite(CSprite **sprite);
  void DestroyNFD(NFD *nfd);
  void DestroyNFD_WeapShield(void);
  void ClearNFD(void);
  void InitNFD(void);

  void InitControlsWeaponShieldPre(void);

  void InitOpenGL();
  void SetCameraDefault(void);
  void CameraSet(void);
  void GLZoom(void);
  void GLPan(void);

  bool SpriteSetMob(CSprite **sprite, char *dispname);
  bool SpriteSetPCBody(CSprite **sprite, char *dispname, char *fname_base, bool male);
  void DestroySprites_GM2(void);
  bool SpriteSetPCHead(CSprite **sprite, bool male);
  bool SpriteSetPCAcc(CSprite **sprite, char *dispname, int no, bool male);
  bool SpriteSetPCWeapon(CSprite **sprite, char *dispname, char *bodyname, char *sexname);
  bool SpriteSetPCWeaponAftImage(char *fname, char *bodyname, char *sexname, int idWeapon);
  bool SpriteSetPCShield(CSprite **sprite, char *bodyname, char *sexname, char *dispname);
  bool SpriteSetNPC(CSprite **sprite, char *dispname);
  bool SpriteSet(CSprite **sprite, char *actname, char *sprname);
  void DrawSprites(void);
  void DrawSpritesHead(CSprite *sprite, int x, int y);

  void InitNumActPat(void);
  void SetNullSprites(void);

  void SelectAct(int idAct);
  void SelectDirection(int idAct, int idDirection);

  void SetWeaponName(char *fnp, char *bodynameW, char *bodyname2);
  void SetShieldName(char *fnp, char *bodynameS, char *bodyname2);

  void GetPCBodyName(char *bodyname, char *sexname, char *dispname, bool male);

  int GetTimeInterval(void);
};


extern "C" {
int NAME_FvsDSortFuncByDisp(const void *a, const void *b);
}

#define PC_ACTNAME_INT "PCActName%d"
#define MOB_ACTNAME_INT "MobActName%d"

#define MALE_STR "\263\262"
#define FEMALE_STR "\277\251"
#define AFTERIMAGE_STR "\260\313\261\244"
#define AFTIMG_ADD_STR "\137\260\313\261\244"
#define SHORTSWORD_AFTIMG_STR "\264\334\260\313\137\260\313\261\244"
#define SWORD_AFTIMG_STR "\260\313\137\260\313\261\244"
#define AXE_AFTIMG_STR "\265\265\263\242\137\260\313\261\244"
#define SPEAR_AFTIMG_STR "\303\242\137\260\313\261\244"
#define ROD_AFTIMG_STR "\267\324\265\345\137\260\313\261\244"
#define CRUB_AFTIMG_STR "\305\254\267\264\137\260\313\261\244"
#define CLAW_AFTIMG_STR "\263\312\305\254\137\260\313\261\244"

//#define MOB_DIR "data\\sprite\\����\\"
#define MOB_DIR "\144\141\164\141\134\163\160\162\151\164\145\134\270\363\275\272\305\315\134"
//#define PCBODY_M_DIR "data\sprite\�ΰ���\��ŁE��\"
#define PCBODY_M_DIR "\144\141\164\141\134\163\160\162\151\164\145\134\300\316\260\243\301\267\134\270\366\305\353\134\263\262\134"
//#define PCBODY_F_DIR "data\sprite\�ΰ���\��ŁE��\"
#define PCBODY_F_DIR "\144\141\164\141\134\163\160\162\151\164\145\134\300\316\260\243\301\267\134\270\366\305\353\134\277\251\134"
//#define PCHEAD_M_DIR "data\sprite\�ΰ���\�Ӹ�ŁE��\"
#define PCHEAD_M_DIR "\144\141\164\141\134\163\160\162\151\164\145\134\300\316\260\243\301\267\134\270\323\270\256\305\353\134\263\262\134"
//#define PCHEAD_F_DIR "data\sprite\�ΰ���\�Ӹ�ŁE��\"
#define PCHEAD_F_DIR "\144\141\164\141\134\163\160\162\151\164\145\134\300\316\260\243\301\267\134\270\323\270\256\305\353\134\277\251\134"
//#define PCACC_M_DIR "data\sprite\�Ǽ��縮\��\"
#define PCACC_M_DIR "\144\141\164\141\134\163\160\162\151\164\145\134\276\307\274\274\273\347\270\256\134\263\262\134"
//#define PCACC_F_DIR "data\sprite\�Ǽ��縮\��\"
#define PCACC_F_DIR "\144\141\164\141\134\163\160\162\151\164\145\134\276\307\274\274\273\347\270\256\134\277\251\134"
//#define WEAPON_DIR "data\sprite\�ΰ���\"
#define WEAPON_DIR "\144\141\164\141\134\163\160\162\151\164\145\134\300\316\260\243\301\267\134"
//#define SHIELD_DIR "data\sprite\����"\"
#define SHIELD_DIR "\144\141\164\141\134\163\160\162\151\164\145\134\271\346\306\320\134"
#define NPC_DIR "data\\sprite\\npc\\"

//#define BAPHOMET_PET "baphomet_���ٱ�����"
#define BAPHOMET_PET "\142\141\160\150\157\155\145\164\137\273\301\264\331\261\270\270\360\300\332"
//#define BON_GON_PET "bon_gun_��ȯ�����"
#define BON_GON_PET "\142\157\156\137\147\165\156\137\277\265\310\257\265\265\273\347\260\313"
//#define CHOCHO_PET "chocho_�浶��E"
#define CHOCHO_PET "\143\150\157\143\150\157\137\271\346\265\266\270\351"
//#define DESERT_WOLF_B_PET "desert_wolf_b_��Eֺ��Ӹ�"
#define DESERT_WOLF_B_PET "\144\145\163\145\162\164\137\167\157\154\146\137\142\137\277\354\301\326\272\271\270\323\270\256"
//#define DEVIRUCHI_PET "deviruchi_������E"
#define DEVIRUCHI_PET "\144\145\166\151\162\165\143\150\151\137\301\245\262\300\301\366"
//#define DOKEBI_PET "dokebi_���ķθӸ�"
#define DOKEBI_PET "\144\157\153\145\142\151\137\276\306\310\304\267\316\270\323\270\256"
//#define ISIS_PET "isis_Ŭ������Ʈ��Ӹ���E"
#define ISIS_PET "\151\163\151\163\137\305\254\267\271\277\300\306\304\306\256\266\363\270\323\270\256\266\354"
//#define LUNATIC_PET "lunatic_����"
#define LUNATIC_PET "\154\165\156\141\164\151\143\137\270\256\272\273"
//#define MUNAK_PET "munak_�����"
#define MUNAK_PET "\155\165\156\141\153\137\277\344\274\372\272\300"
//#define ORK_WARRIOR_PET "ork_warrior_��"
#define ORK_WARRIOR_PET "\157\162\153\137\167\141\162\162\151\157\162\137\262\311"
//#define PECOPECO_PET "pecopeco_����E"
#define PECOPECO_PET "\160\145\143\157\160\145\143\157\137\263\277\272\361"
//#define PETIT_PET "petit_��"
#define PETIT_PET "\160\145\164\151\164\137\272\260"
//#define PICKEY_PET "picky_�˲���E"
#define PICKY_PET "\160\151\143\153\171\137\276\313\262\256\301\372"
//#define PORING_PET "poring_å����E"
#define PORING_PET "\160\157\162\151\156\147\137\303\245\260\241\271\346"
//#define ROCKER_PET "rocker_�޶ѱ�Ȱ�E"
#define ROCKER_PET "\162\157\143\153\145\162\137\270\336\266\321\261\342\276\310\260\346"
//#define SAVAGE_BABE_PET "savage_babe_���̽�"
#define SAVAGE_BABE_PET "\163\141\166\141\147\145\137\142\141\142\145\137\267\271\300\314\275\272"
//#define SMOKIE_PET "smokie_���÷�"
#define SMOKIE_PET "\163\155\157\153\151\145\137\270\323\307\303\267\257"
//#define SOHEE_PET "sohee_�濁E"
#define SOHEE_PET "\163\157\150\145\145\137\271\346\277\357"
//#define SPORE_PET "spore_���ֹ�ġ��"
#define SPORE_PET "\163\160\157\162\145\137\277\370\301\326\271\316\304\241\270\266"
//#define YOYO_PET "yoyo_�Ӹ���E"
#define YOYO_PET "\171\157\171\157\137\270\323\270\256\266\354"

static int weaponid2type[][2] = {
  // 0: short sword
  // 1: one hand sword
  // 2: two hand sword
  // 3: axe
  // 4: spear
  // 5: rod
  // 6: crub
  // 7: book
  // 8: claw
  // 9: inst
  // 10: whip
  // 11: katar?
  1101, 1,  //�\�[�h
  1102, 1,  //�\�[�h
  1103, 1,  //�\�[�h
  1104, 1,  //�t�@���V�I��
  1105, 1,  //�t�@���V�I��
  1106, 1,  //�t�@���V�I��
  1107, 1,  //�u���C�h
  1108, 1,  //�u���C�h
  1109, 1,  //�u���C�h
  1110, 1,  //���C�s�A
  1111, 1,  //���C�s�A
  1112, 1,  //���C�s�A
  1113, 1,  //�V�~�^�[
  1114, 1,  //�V�~�^�[
  1115, 1,  //�V�~�^�[
  1116, 2,  //�J�^�i
  1117, 2,  //�J�^�i
  1118, 2,  //�J�^�i
  1119, 1,  //�c���M
  1120, 1,  //�c���M
  1121, 1,  //�c���M
  1122, 1,  //������
  1123, 1,  //�C����
  1124, 1,  //�I�[�L�b�V���\�[�h
  1125, 1,  //������
  1126, 1,  //�T�[�x��
  1127, 1,  //�T�[�x��
  1128, 1,  //�C����
  1129, 1,  //�t�����x���W�F
  1130, 1,  //�l�C�K��
  1131, 1,  //�A�C�X�t�@���V�I��
  1132, 1,  //�G�b�W
  1133, 1,  //�t�@�C�A�[�u�����h
  1134, 1,  //�V�[�U�[�Y�\�[�h
  1135, 1,  //�J�g���X
  1136, 1,  //���z��
  1137, 1,  //�G�N�X�L�����o�[
  1138, 1,  //�~�X�e�[���e�C��
  1139, 1,  //�e�C���t�B���O
  1140, 1,  //�ʉ_��
  1141, 1,  //���`��
  1142, 1,  //�W���G���\�[�h
  1143, 1,  //�K�C�A�\�[�h
  1144, 1,  //�h�g�
  1145, 1,  //�z�[���[�A���F���W���[
  //1151, 2,  //�X���C���[
  //1152, 2,  //�X���C���[
  //1153, 2,  //�X���C���[
  //1154, 2,  //�o�X�^�[�h�\�[�h
  //1155, 2,  //�o�X�^�[�h�\�[�h
  //1156, 2,  //�o�X�^�[�h�\�[�h
  //1157, 2,  //�c�[�n���h�\�[�h
  //1158, 2,  //�c�[�n���h�\�[�h
  //1159, 2,  //�c�[�n���h�\�[�h
  //1160, 2,  //�u���[�h�\�[�h
  //1161, 2,  //�o������
  //1162, 2,  //�u���[�h�\�[�h
  //1163, 2,  //�N���C���A
  //1164, 2,  //����
  //1165, 2,  //���@
  //1166, 2,  //�h���S���X���C���[
  //1167, 2,  //�V���o�C�`�F���V���x��
  //1168, 2,  //�c���@�C�n���_�[
  //1169, 2,  //�G�N�X�L���[�V���i�[
  //1170, 2,  //�J�b�c�o���Q��
  1201, 0,  //�i�C�t
  1202, 0,  //�i�C�t
  1203, 0,  //�i�C�t
  1204, 0,  //�J�b�^�[
  1205, 0,  //�J�b�^�[
  1206, 0,  //�J�b�^�[
  1207, 0,  //�}�C���S�[�V��
  1208, 0,  //�}�C���S�[�V��
  1209, 0,  //�}�C���S�[�V��
  1210, 0,  //�_�[�N
  1211, 0,  //�_�[�N
  1212, 0,  //�_�[�N
  1213, 0,  //�_�K�[
  1214, 0,  //�_�K�[
  1215, 0,  //�_�K�[
  1216, 0,  //�X�e�B���b�g
  1217, 0,  //�X�e�B���b�g
  1218, 0,  //�X�e�B���b�g
  1219, 0,  //�O���f�B�E�X
  1220, 0,  //�O���f�B�E�X
  1221, 0,  //�O���f�B�E�X
  1222, 0,  //�_�}�X�J�X
  1223, 0,  //�t�H�[�`�����\�[�h
  1224, 0,  //�\�[�h�u���C�J�[
  1225, 0,  //���C���u���C�J�[
  1226, 0,  //�_�}�X�J�X
  1227, 0,  //�E�B�[�_�[�i�C�t
  1228, 0,  //�R���o�b�g�i�C�t
  1229, 0,  //�
  1230, 0,  //��
  1231, 0,  //�o�[�����h
  1232, 0,  //�A�T�V���_�K�[
  1233, 0,  //�G�L�T�[�T�C�Y
  1234, 0,  //������
  1235, 0,  //�A�]�[�g
  1236, 0,  //�X�N�T�}�b�h
  1237, 0,  //�I�[�K�g�D�[�X
  1238, 0,  //�[�j�[�i�C�t
  1239, 0,  //�|�C�Y���i�C�t
  1240, 0,  //�v�����Z�X�i�C�t
  1241, 0,  //�J�[�X�_�K�[
  1242, 0,  //�J�E���^�[�_�K�[
  //1250, 11,  //�W����
  //1251, 11,  //�W����
  //1252, 11,  //�J�^�[��
  //1253, 11,  //�J�^�[��
  //1254, 11,  //�W���}�_�n��
  //1255, 11,  //�W���}�_�n��
  1301, 3,  //�A�b�N�X
  1302, 3,  //�A�b�N�X
  1303, 3,  //�A�b�N�X
  1304, 3,  //�I�[�L�b�V���A�b�N�X
  1305, 3,  //�N���[���@�[
  1306, 3,  //�E�H�[�A�N�X
  1351, 3,  //�o�g���A�b�N�X
  1352, 3,  //�o�g���A�b�N�X
  1353, 3,  //�o�g���A�b�N�X
  1354, 3,  //�n���}�[
  1355, 3,  //�n���}�[
  1356, 3,  //�n���}�[
  1357, 3,  //�o�X�^�[
  1358, 3,  //�o�X�^�[
  1359, 3,  //�o�X�^�[
  1360, 3,  //�c�[�n���h�A�b�N�X
  1361, 3,  //�c�[�n���h�A�b�N�X
  1362, 3,  //�c�[�n���h�A�b�N�X
  1363, 3,  //�u���b�h�A�b�N�X
  1364, 3,  //�O���C�g�A�b�N�X
  1365, 3,  //�T�o�X
  1366, 3,  //���C�g�G�v�V����
  1367, 3,  //�X���[�^�[
  1368, 3,  //�g�}�z�[�N
  1369, 3,  //�M���`��
  1401, 4,  //�W���x����
  1402, 4,  //�W���x����
  1403, 4,  //�W���x����
  1404, 4,  //�X�s�A�[
  1405, 4,  //�X�s�A�[
  1406, 4,  //�X�s�A�[
  1407, 4,  //�p�C�N
  1408, 4,  //�p�C�N
  1409, 4,  //�p�C�N
  1410, 4,  //�����X
  1411, 4,  //�����X
  1412, 4,  //�����X
  1413, 4,  //�O���O�j�[��
  1414, 4,  //�Q���h���A
  1415, 4,  //��
  1416, 4,  //�e�����O���e�B�[
  1417, 4,  //�|�[���A�N�X
  1451, 4,  //�M�U����
  1452, 4,  //�M�U����
  1453, 4,  //�M�U����
  1454, 4,  //�O���C��
  1455, 4,  //�O���C��
  1456, 4,  //�O���C��
  1457, 4,  //�p���`�U��
  1458, 4,  //�p���`�U��
  1459, 4,  //�p���`�U��
  1460, 4,  //�g���C�f���g
  1461, 4,  //�g���C�f���g
  1462, 4,  //�g���C�f���g
  1463, 4,  //�n���o�[�h
  1464, 4,  //�n���o�[�h
  1465, 4,  //�n���o�[�h
  1466, 4,  //�N���Z���g�T�C�_�[
  1467, 4,  //�r���M�U����
  1468, 4,  //�[�s�����X
  1469, 4,  //�����M�k�X�̑�
  1470, 4,  //�u�����[�i�N
  1471, 4,  //�w���t�@�C�A
  1472, 5,  //�X�^�b�t�I�u�\�E��
  1473, 5,  //�E�B�U�[�h�X�^�b�t
  1501, 6,  //�N���u
  1502, 6,  //�N���u
  1503, 6,  //�N���u
  1504, 6,  //���C�X
  1505, 6,  //���C�X
  1506, 6,  //���C�X
  1507, 6,  //�X�}�b�V���[
  1508, 6,  //�X�}�b�V���[
  1509, 6,  //�X�}�b�V���[
  1510, 6,  //�t���C��
  1511, 6,  //�t���C��
  1512, 6,  //�t���C��
  1513, 6,  //���j���O�X�^�[
  1514, 6,  //���j���O�X�^�[
  1515, 6,  //���j���O�X�^�[
  1516, 6,  //�\�[�h���C�X
  1517, 6,  //�\�[�h���C�X
  1518, 6,  //�\�[�h���C�X
  1519, 6,  //�`�F�C��
  1520, 6,  //�`�F�C��
  1521, 6,  //�`�F�C��
  1522, 6,  //�X�^�i�[
  1523, 6,  //�X�p�C�N
  1524, 6,  //�S�[���f�����C�X
  1525, 6,  //�����O���C�X
  1526, 6,  //�X���b�V�� 
  1527, 6,  //�J�h���[��
  1528, 6,  //�O�����h�N���X
  1529, 6,  //�A�C�A���h���C�o�[
  1530, 6,  //�~�����j�[��
  1531, 6,  //�X�p�i
  //1550, ,  //�u�b�N
  //1551, ,  //�o�C�u��
  //1552, ,  //�^�u���b�g
  1601, 5,  //���b�h
  1602, 5,  //���b�h
  1603, 5,  //���b�h
  1604, 5,  //�����h
  1605, 5,  //�����h
  1606, 5,  //�����h
  1607, 5,  //�X�^�b�t
  1608, 5,  //�X�^�b�t
  1609, 5,  //�X�^�b�t
  1610, 5,  //�A�[�N�����h
  1611, 5,  //�A�[�N�����h
  1612, 5,  //�A�[�N�����h
  1613, 5,  //�}�C�g�X�^�b�t
  1614, 5,  //�_���̏�
  1615, 5,  //�[���̏�
  //1701, ,  //�{�E
  //1702, ,  //�{�E
  //1703, ,  //�{�E
  //1704, ,  //�R���|�W�b�g�{�E
  //1705, ,  //�R���|�W�b�g�{�E
  //1706, ,  //�R���|�W�b�g�{�E
  //1707, ,  //�O���C�g�{�E
  //1708, ,  //�O���C�g�{�E
  //1709, ,  //�O���C�g�{�E
  //1710, ,  //�N���X�{�E
  //1711, ,  //�N���X�{�E
  //1712, ,  //�N���X�{�E
  //1713, ,  //�A�[�o���X�g
  //1714, ,  //�p�|
  //1715, ,  //�A�[�o���X�g
  //1716, ,  //�p�|
  //1718, ,  //�n���^�[�{�E
  //1719, ,  //�����̋|
  //1720, ,  //���h���̋|
  //1721, ,  //�A�W
  //1722, ,  //�o���X�^
  1801, 8,  //�o�O�i�E
  1802, 8,  //�o�O�i�E
  1803, 8,  //�i�b�N���_�X�^�[
  1804, 8,  //�i�b�N���_�X�^�[
  1805, 8,  //�z��
  1806, 8,  //�z��
  1807, 8,  //�t�B�X�g
  1808, 8,  //�t�B�X�g
  1809, 8,  //�N���[
  1810, 8,  //�N���[
  1811, 8,  //�t�B���K�[
  1812, 8,  //�t�B���K�[
  1813, 8,  //�J�C�U�[�i�b�N��
  1814, 8  //�x���Z���N
  //1901, ,  //�o�C�I����
  //1902, ,  //�o�C�I����
  //1903, ,  //�}���h����
  //1904, ,  //�}���h����
  //1905, ,  //�����[�g
  //1906, ,  //�����[�g
  //1907, ,  //�M�^�[
  //1908, ,  //�M�^�[
  //1909, ,  //�n�[�v
  //1910, ,  //�n�[�v
  //1911, ,  //�S�����S
  //1912, ,  //�S�����S
  //1950, ,  //���[�v
  //1951, ,  //���[�v
  //1952, ,  //���C��
  //1953, ,  //���C��
  //1954, ,  //���C���[
  //1955, ,  //���C���[
  //1956, ,  //�����e
  //1957, ,  //�����e
  //1958, ,  //�e�C��
  //1959, ,  //�e�C��
  //1960, ,  //�z�C�b�v
  //1961, ,  //�z�C�b�v
  //1962, ,  //�����G�b�g
  //1963, ,  //���v�`���[���[�Y
  //1964, ,  //�V�����e�B
};

#endif // __MY_CHRVIEW__
