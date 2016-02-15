#ifndef ___AAA_Vector___
#define ___AAA_Vector___

class Vec {
public:
  float  x, y, z;
  Vec();
  Vec(float a, float b, float c);
  Vec(const Vec& v);
  Vec& operator =(const Vec& v);
  friend Vec operator +(const Vec& a, const Vec& b);
  friend Vec operator -(const Vec& a, const Vec& b);
  friend Vec operator *(const Vec& a, float b);
  friend Vec operator *(float b, const Vec& a);
  friend Vec operator /(const Vec& a, float b);
  // ����
  friend double operator *(const Vec& a, const Vec& b);
  // �O��
  friend Vec operator ^(const Vec& a, const Vec& b);
  // �X�J���[��Ԃ�
  float magnitude(void);
  // ���K��
  void normalize(void);
  // ���̃x�N�g������ɉ�]�������_��Ԃ�(�I�t�Z�b�g�t�j
  void ThisAxisRotOffNorm(Vec *p, float degree, Vec *offs);
  // ���̃x�N�g������ɉ�]�������_��Ԃ�
  void ThisAxisRot(Vec *p, float degree);
  // �����̂Q���Ԃ�
  float CalcDistance2(Vec a);
  // ���̓_���O�p�`abc�̒��ɂ��邩���ׂ�i���̓_�͕��ʂɏ���Ă���̂Ƃ���j
  bool CheckInTriangle(Vec a, Vec b, Vec c);
  // ���̓_��a, b�ō���镽�ʂ̖@���x�N�g����Ԃ�
  Vec CalcPlaneNorm(Vec a, Vec b);
  // �_p��ʂ�@���x�N�g��norm�̕��ʂƂ��̓_��ʂ�x�N�g��v�̌�_�����߂�
  Vec CalcIntersectPoint(Vec norm, Vec p, Vec v);
  // ���̓_��ʂ�x�N�g��dir�ƎO�p�`ABC�̋U�d�S�Ƃ̍ŒZ�����ɂ���_�ł̃p�����[�^�����߂�
  float CalcLineParam(Vec dir, Vec a, Vec b, Vec c);
};

#endif
