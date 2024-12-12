#include <stdio.h>

int main() {
    int NDTPS, NDGB, NDLK;
    float skorDosenTetap, skorJabatanAkademik;
    int evaluasiKurikulum;
    float skorKurikulum;
    int aspekSPMI;
    float skorPenjaminanMutu;
    float PBS, skorTracerStudy;
    int RI, RN, RL;
    float skorPublikasi;
    float persentaseSangatBaik, persentaseBaik, persentaseCukup, persentaseKurang;
    float skorKepuasan;

    printf("=== Program Penilaian Akreditasi ===\n");

    printf("Masukkan jumlah Dosen Tetap Penugasan Khusus (NDTPS): ");
    scanf("%d", &NDTPS);

    if (NDTPS >= 6) {
        skorDosenTetap = 4;
    } else if (NDTPS >= 3) {
        skorDosenTetap = (2.0 * NDTPS) / 3;
    } else {
        skorDosenTetap = 0;
    }

    printf("Masukkan jumlah DTPS dengan jabatan akademik Guru Besar: ");
    scanf("%d", &NDGB);
    printf("Masukkan jumlah DTPS dengan jabatan akademik Lektor Kepala: ");
    scanf("%d", &NDLK);

    float PGBLK = ((float)(NDGB + NDLK) / NDTPS) * 100;
    if (PGBLK >= 70) {
        skorJabatanAkademik = 4;
    } else {
        skorJabatanAkademik = 2 + ((20 * PGBLK) / 7);
    }

    printf("Masukkan skor evaluasi kurikulum (1-4): ");
    scanf("%d", &evaluasiKurikulum);
    if (evaluasiKurikulum >= 1 && evaluasiKurikulum <= 4) {
        skorKurikulum = evaluasiKurikulum;
    } else {
        skorKurikulum = 0;
    }

    printf("Masukkan jumlah aspek SPMI yang terpenuhi (0-5): ");
    scanf("%d", &aspekSPMI);
    if (aspekSPMI == 5) {
        skorPenjaminanMutu = 4;
    } else if (aspekSPMI == 4) {
        skorPenjaminanMutu = 3;
    } else if (aspekSPMI == 3) {
        skorPenjaminanMutu = 2;
    } else if (aspekSPMI >= 1 && aspekSPMI <= 2) {
        skorPenjaminanMutu = 1;
    } else {
        skorPenjaminanMutu = 0;
    }

    printf("Masukkan persentase kesesuaian bidang kerja (PBS): ");
    scanf("%f", &PBS);
    if (PBS >= 60) {
        skorTracerStudy = 4;
    } else {
        skorTracerStudy = (20 * PBS) / 3;
    }

    printf("Masukkan jumlah publikasi internasional bereputasi (RI): ");
    scanf("%d", &RI);
    printf("Masukkan jumlah publikasi nasional terakreditasi (RN): ");
    scanf("%d", &RN);
    printf("Masukkan jumlah publikasi lokal (RL): ");
    scanf("%d", &RL);

    if (RI >= 2) {
        skorPublikasi = 4;
    } else if (RI < 2 && RN >= 20) {
        skorPublikasi = 3 + ((float)RI / 2);
    } else if (RI == 0 && RN == 0 && RL >= 70) {
        skorPublikasi = 2;
    } else {
        skorPublikasi = 0;
    }

    printf("Masukkan persentase 'sangat baik': ");
    scanf("%f", &persentaseSangatBaik);
    printf("Masukkan persentase 'baik': ");
    scanf("%f", &persentaseBaik);
    printf("Masukkan persentase 'cukup': ");
    scanf("%f", &persentaseCukup);
    printf("Masukkan persentase 'kurang': ");
    scanf("%f", &persentaseKurang);

    skorKepuasan = (4 * persentaseSangatBaik + 3 * persentaseBaik + 2 * persentaseCukup + 1 * persentaseKurang) / 100;

    printf("\n=== Hasil Skor Akreditasi ===\n");
    printf("1. Skor Dosen Tetap (DTPS): %.2f\n", skorDosenTetap);
    printf("2. Skor Jabatan Akademik DTPS: %.2f\n", skorJabatanAkademik);
    printf("3. Skor Evaluasi Kurikulum: %.2f\n", skorKurikulum);
    printf("4. Skor Penjaminan Mutu Internal: %.2f\n", skorPenjaminanMutu);
    printf("5. Skor Tracer Study: %.2f\n", skorTracerStudy);
    printf("6. Skor Publikasi Ilmiah Mahasiswa: %.2f\n", skorPublikasi);
    printf("7. Skor Kepuasan Pengguna: %.2f\n", skorKepuasan);

    return 0;
}